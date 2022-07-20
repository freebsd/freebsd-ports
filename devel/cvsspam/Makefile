PORTNAME=	cvsspam
PORTVERSION=	0.2.12
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.badgers-in-foil.co.uk/projects/cvsspam/releases/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Sends diffs when a change is committed to your CVS repository

LICENSE=	GPLv2

USE_RUBY=	yes
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	COPYING CREDITS TODO cvsspam-doc.html cvsspam-doc.pdf

OPTIONS_DEFINE=	DOCS

post-patch:
.for f in collect_diffs.rb cvsspam.rb record_lastdir.rb
	@${REINPLACE_CMD} -e 's|/usr/bin/ruby|${RUBY}|' \
		${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -E 's|/etc/cvsspam/(cvsspam\.conf)|${PREFIX}/etc/\1|' \
		${WRKSRC}/collect_diffs.rb

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
.for f in collect_diffs.rb cvsspam.rb record_lastdir.rb
	${INSTALL_SCRIPT} ${WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
.endfor
	${INSTALL_DATA} ${WRKSRC}/cvsspam.conf \
		${STAGEDIR}${PREFIX}/etc/cvsspam.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
