# New ports collection makefile for:	php-ice
# Date created:				2007-08-21
# Whom:					DIrk Ye <dirk.ye@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Ice
PORTVERSION=	3.2.1
CATEGORIES=	devel
MASTER_SITES=	http://www.zeroc.com/download/Ice/3.2/ \
		http://www.dirk.sh/dirk/php/Ice/
PKGNAMEPREFIX=	php5-
DISTNAME=	IcePHP-${PORTVERSION}

MAINTAINER=	dirk.ye@gmail.com
COMMENT=	An Ice (Internet Communications Engine) language mapping for PHP

LIB_DEPENDS=	Ice.32:${PORTSDIR}/devel/ice

USE_GMAKE=	yes
MAKE_ARGS+=	PHP_EXT_DIR=${PHP_EXT_DIR}
DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4
USE_PHP=	yes
USE_PHP_BUILD=	yes

LIB_VRS=	${PORTVERSION:S|.||g:C|0$||}
PHP_MODNAME?=	IcePHP

CFLAGS+=	-ftemplate-depth-128 -fPIC -DPIC -Wall -D_REENTRANT ${PTHREAD_CFLAGS}
.if defined(DEBUG)
CFLAGS+=	-g
.else
CFLAGS+=	-DNDEBUG
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		does not compile
.endif

.if ((${ARCH} != i386) && (${ARCH} != powerpc))
MAKE_ENV=	LP64=yes
.endif

post-extract:
	${CP} ${WRKSRC}/config/Make.rules.Linux ${WRKSRC}/config/Make.rules.FreeBSD

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' ${WRKSRC}/config/Make.rules.FreeBSD
	${REINPLACE_CMD} 's|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/config/Make.rules
post-install:
	@${ECHO_CMD} extension=${PHP_MODNAME}.so \
		>> ${PREFIX}/etc/php/extensions.ini
	@${ECHO_CMD} "****************************************************************************"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "The following line has been added to your ${PREFIX}/etc/php/extensions.ini"
	@${ECHO_CMD} "configuration file to automatically load the installed extension:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "extension=${PHP_MODNAME}.so"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "****************************************************************************"

.include <bsd.port.post.mk>
