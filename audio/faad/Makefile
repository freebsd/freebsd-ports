# New ports collection makefile for:	faad
# Date created:			8 January 2003
# Whom:				Sean McGovern <sean@sfarc.net>
#
# $FreeBSD$
#

PORTNAME=	faad2
PORTVERSION=	1.1
CATEGORIES=	audio
MASTER_SITES=	http://faac.sourceforge.net/files/

MAINTAINER=	sean@sfarc.net

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_AUTOMAKE_VER= 15
AUTOMAKE_ARGS=	--add-missing

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS=	--program-transform-name=''
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \

INSTALLS_SHLIB=	yes

post-patch:
# make sure everything is prepared prior to configure stage
# pre-configure will not work since *AUTO* tools happen in-between
	@cd ${WRKSRC}; ${ACLOCAL} -I ${ACLOCAL_DIR} -I .; libtoolize \
		--automake
# CFLAGS safeness
	@${FIND} ${WRKSRC} -type f -name Makefile.am | \
		${XARGS} -n 5 -x \
			${REINPLACE_CMD} -e \
				's|-O2|${CFLAGS}|' 

post-configure:
# sync the multiple libtool copies
	@${CP} ${WRKSRC}/${LIBTOOL} ${WRKSRC}/common/mp4v2/

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--build=${CONFIGURE_TARGET}

.include <bsd.port.post.mk>
