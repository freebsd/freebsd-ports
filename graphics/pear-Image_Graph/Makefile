# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	Image_Graph
PORTVERSION=	0.8.0
CATEGORIES=	graphics www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An OO PEAR graph rendering package

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log \
		${PEARDIR}/Image/Canvas.php:${PORTSDIR}/graphics/pear-Image_Canvas

PEAR_AUTOINSTALL=	yes
USE_PHP=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*php$$
DEFAULT_PHP_VER=	5 

LATEST_LINK=	pear-Image_Graph

.include <bsd.port.pre.mk>
post-patch:
# don't modify images
.for file in ${FILES}
	@if ${ECHO_CMD} ${file} | ${GREP} -q -e "php$$" ; then \
		${REINPLACE_CMD} -e "s|@package_version@|${DISTVERSION}|" ${WRKSRC}/${file}; \
	fi
.endfor

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
