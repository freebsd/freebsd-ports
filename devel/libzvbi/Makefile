# New ports collection makefile for:	libzvbi
# Date created:				15 May 2003
# Whom:					Oliver Lehmann <oliver@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libzvbi
PORTVERSION=	0.2.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	zapping
DISTNAME=	${PORTNAME:S/lib//}-${PORTVERSION}

MAINTAINER=	oliver@freebsd.org
COMMENT=	Routines to access raw VBI capture devices

LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png \
		intl.4:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE}/include \
		--with-libintl-prefix=${LOCALBASE}/include

CONFIGURE_ENV=	CC="$(CC) -I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib -L/usr/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
