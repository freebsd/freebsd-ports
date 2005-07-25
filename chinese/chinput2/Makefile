# ex:ts=8
# Ports collection makefile for:	chinput2
# Date created:				11/09/2000
# Whom:					Peng HaiJie   (phj@cn.freebsd.org)
#
# $FreeBSD$
#

PORTNAME=	chinput2
PORTVERSION=	1.3.1
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://ftp.cn.freebsd.org/pub/ported/
DISTNAME=	zh-chinput2-1.3.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another Chinese GB2312 and Big5 X11 input server

BUILD_DEPENDS=	imake:${X_IMAKE_PORT}

USE_MYSQL=	yes
USE_REINPLACE=	yes
USE_XLIB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/chinput2 bin/add_items etc/chinput2.conf share/${PORTNAME}/README
PLIST_DIRS=	share/${PORTNAME}

post-extract:
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -rf

post-patch:
	@${REINPLACE_CMD} -Ee 's,^((BIN|CONF|DOC_)(DIR|PATH)=)/usr/local,\1${PREFIX},g' \
		${WRKSRC}/util/pydb/Makefile ${WRKSRC}/src/Makefile ${WRKSRC}/Makefile

pre-build:
	@${RM} -f ${WRKSRC}/src/.depend

pre-install:
	@${REINPLACE_CMD} -Ee 's,^((BIN|CONF|DOC_)(DIR|PATH)=)/usr/local,\1${PREFIX},g' \
		${WRKSRC}/src/Makefile

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG}
	@${ECHO_MSG} "Please refer to ${PREFIX}/share/chinput2/README for "
	@${ECHO_MSG} "how to use chinput2,thanks for using this software."
	@${ECHO_MSG}
	@${ECHO_MSG} "					-phj@cn.freebsd.org"
	@${ECHO_MSG}

.include <bsd.port.mk>
