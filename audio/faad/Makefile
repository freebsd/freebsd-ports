# New ports collection makefile for:	faad
# Date created:			8 January 2003
# Whom:				Sean McGovern <sean@sfarc.net>
#
# $FreeBSD$
#

PORTNAME=	faad2
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	faac
DISTNAME=	${PORTNAME}-${PORTVERSION}-rc3

MAINTAINER=	sean@sfarc.net
COMMENT=	A LC, MAIN and LTP profile, MPEG2 and MPEG-4 AAC decoder

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_AUTOMAKE_VER=	15
USE_AUTOHEADER=		yes
USE_AUTOHEADER=	yes
AUTOMAKE_ARGS=	--add-missing

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	13
USE_REINPLACE=	yes

CONFIGURE_ARGS=	--program-transform-name='' --with-mp4v2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \

INSTALLS_SHLIB=	yes

pre-patch: build-depends

post-patch:
# make sure everything is prepared prior to configure stage
# pre-configure will not work since *AUTO* tools happen in-between
	@cd ${WRKSRC}; ${ACLOCAL} -I ${ACLOCAL_DIR} -I .; \
		${SETENV} ${SCRIPTS_ENV} ${LIBTOOLIZE} --automake
# CFLAGS safeness
	@${FIND} ${WRKSRC} -type f -name Makefile.am | \
		${XARGS} -n 5 -x \
			${REINPLACE_CMD} -e \
				's|-O2|${CFLAGS}|'

post-configure:
# sync the multiple libtool copies
	@${CP} ${WRKSRC}/libtool ${WRKSRC}/common/mp4v2/

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--build=${CONFIGURE_TARGET}

.include <bsd.port.post.mk>
