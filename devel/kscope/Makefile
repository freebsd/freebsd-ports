# New ports collection makefile for:	kscope
# Date created:		2004-04-21
# Whom:			Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	kscope
PORTVERSION=	0.7
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}/

MAINTAINER=	frank@exit.com
COMMENT=	KDE front-end to Cscope

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags \
		cscope:${PORTSDIR}/devel/cscope

USE_KDELIBS_VER=3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

MAKE_ENV=	EXTRA_LIBRARIES="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

post-patch:
	${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.include <bsd.port.mk>
