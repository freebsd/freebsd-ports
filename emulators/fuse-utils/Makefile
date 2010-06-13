# New ports collection makefile for:	fuse-utils
# Date created:			2007-06-27
# Whom:				Rene Ladan <r.c.ladan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fuse-utils
PORTVERSION=	0.10.0.1
CATEGORIES=	emulators
MASTER_SITES=	SF/fuse-emulator/${PORTNAME}/${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Utilities from the Free Unix Spectrum Emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	spectrum.7:${PORTSDIR}/emulators/libspectrum

OPTIONS=	AUDIOFILE "Build audio <-> tape utilities" on

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

MAN1=	createhdf.1 fuse-utils.1 listbasic.1 raw2hdf.1 rzxcheck.1 rzxdump.1 rzxtool.1 scl2trd.1 snap2tzx.1 snapconv.1 tapeconv.1 tzxlist.1 profile2map.1

.if !defined(WITHOUT_AUDIOFILE)
LIB_DEPENDS+=	audiofile.0:${PORTSDIR}/audio/libaudiofile
PLIST_SUB=	AUDIOFILE=""
MAN1+=		audio2tape.1 tape2wav.1
.else
CONFIGURE_ARGS+=--without-audiofile
PLIST_SUB=	AUDIOFILE="@comment"
.endif

MAKE_JOBS_SAFE=	yes

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
