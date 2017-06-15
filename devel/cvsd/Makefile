# Created by: ijliao
# $FreeBSD$

PORTNAME=	cvsd
PORTVERSION=	1.0.24
CATEGORIES=	devel
MASTER_SITES=	http://arthurdejong.org/cvsd/ \
		http://wiftp.com/

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	CVS pserver daemon

LICENSE=	GPLv2

BUILD_DEPENDS=	cvs:devel/cvs
RUN_DEPENDS=	cvs:devel/cvs

USE_RC_SUBR=	cvsd
USES=		perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libwrap
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

OPTIONS_DEFINE=	DOCS

PORTDOCS=	FAQ NEWS README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsd ${STAGEDIR}${PREFIX}/sbin/cvsd
.for f in cvsd-buginfo cvsd-buildroot cvsd-passwd
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/sbin
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/cvsd
	${INSTALL_DATA} ${WRKSRC}/cvsd.conf-dist ${STAGEDIR}${PREFIX}/etc/cvsd/cvsd.conf.sample
	${INSTALL_MAN} ${WRKSRC}/*.5 ${STAGEDIR}${MAN5PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/*.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
