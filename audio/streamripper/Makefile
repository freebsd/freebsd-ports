# New ports collection makefile for:	streamripper
# Date created:		6 Apr 2000
# Whom:			Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	streamripper
PORTVERSION=	1.62.1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Splits SHOUTcast stream into tracks

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		tre.6:${PORTSDIR}/textproc/libtre

OPTIONS=	FAAD "Include FAAD mpeg4 codec support" on \
		VORBIS "Include Ogg Vorbis codec support" on

USE_GNOME=	gnometarget
USE_ICONV=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-included-libmad \
		--without-included-tre \
		--with-included-argv
CFLAGS+=	-DANSI_PROTOTYPES -DHAVE_LANGINFO_CODESET

MAN1=		streamripper.1
PLIST_FILES=	bin/cstreamripper bin/streamripper

.include <bsd.port.pre.mk>

.if defined(WITHOUT_FAAD)
CONFIGURE_ARGS+=	ac_cv_lib_faad_NeAACDecDecode2=no
.else
LIB_DEPENDS+=	faad.0:${PORTSDIR}/audio/faad
.endif

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=	--without-ogg
.else
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.endif

post-patch:
	@${REINPLACE_CMD} -e '/if test/s|==|=|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cstreamripper ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/streamripper ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/streamripper.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
