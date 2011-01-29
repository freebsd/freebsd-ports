# New ports collection makefile for:	fuse-utils
# Date created:			2007-06-27
# Whom:				Rene Ladan <r.c.ladan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fuse-utils
PORTVERSION=	1.0.0
CATEGORIES=	emulators
MASTER_SITES=	SF/fuse-emulator/${PORTNAME}/${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Utilities from the Free Unix Spectrum Emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_JOBS_SAFE=	yes

LIB_DEPENDS=	spectrum.8:${PORTSDIR}/emulators/libspectrum
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libspectrum-prefix=${LOCALBASE} \
		--with-local-prefix=${LOCALBASE}

MAN1=	createhdf.1 fuse-utils.1 listbasic.1 raw2hdf.1 rzxcheck.1 rzxdump.1 rzxtool.1 scl2trd.1 snap2tzx.1 snapconv.1 tapeconv.1 tzxlist.1 profile2map.1

.include <bsd.port.options.mk>

OPTIONS=	AUDIOFILE "Build audio <-> tape utilities" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_AUDIOFILE)
LIB_DEPENDS+=	audiofile.0:${PORTSDIR}/audio/libaudiofile
PLIST_SUB=	AUDIOFILE=""
MAN1+=		audio2tape.1 tape2wav.1
.else
CONFIGURE_ARGS+=--without-audiofile
PLIST_SUB=	AUDIOFILE="@comment "
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
