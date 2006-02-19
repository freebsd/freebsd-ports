# New ports collection makefile for:	cvsspam
# Date created:				16 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	cvsspam
PORTVERSION=	0.2.12
CATEGORIES=	devel
MASTER_SITES=	http://www.badgers-in-foil.co.uk/projects/cvsspam/releases/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Sends diffs when a change is committed to your CVS repository

USE_RUBY=	yes
NO_BUILD=	yes

PORTDOCS=	COPYING CREDITS TODO cvsspam-doc.html cvsspam-doc.pdf

post-patch:
.for f in collect_diffs.rb cvsspam.rb record_lastdir.rb
	@${REINPLACE_CMD} -e 's|/usr/bin/ruby|${RUBY}|' \
		${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -E 's|/etc/cvsspam/(cvsspam\.conf)|${PREFIX}/etc/\1|' \
		${WRKSRC}/collect_diffs.rb

do-install:
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
.for f in collect_diffs.rb cvsspam.rb record_lastdir.rb
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/libexec/${PORTNAME}
.endfor
	${INSTALL_DATA} ${WRKSRC}/cvsspam.conf ${PREFIX}/etc/cvsspam.conf.default
.if !exists(${PREFIX}/etc/cvsspam.conf)
	${INSTALL_DATA} ${WRKSRC}/cvsspam.conf ${PREFIX}/etc/cvsspam.conf
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
