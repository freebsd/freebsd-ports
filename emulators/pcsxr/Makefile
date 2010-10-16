# New ports collection makefile for:	pcsxr
# Date created:		11 June 2010
# Whom:			Ganael Laplanche <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	pcsxr
PORTVERSION=	1.9.91
PORTREVISION=	1
CATEGORIES=	emulators
# Original URLs :
# http://download.codeplex.com/Project/Download/FileDownload.aspx?ProjectName=pcsxr&DownloadId=98581&FileTime=129064504645100000&Build=16694
# http://sourceforge.net/projects/pcsx-df/files/pcsx-df/1.10/pcsx-df-1.10.tar.gz/download
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		pcsx-df-1.10-plugin-dfbinimage2${EXTRACT_SUFX}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Playstation (PSX) emulator

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk
LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis

ONLY_FOR_ARCHS=	i386 amd64

USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf:268:env aclocal:111:env automake:111:env libtool:22
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-opengl
USE_LDCONFIG=	yes
USE_DOS2UNIX=	yes

USE_GNOME=	gtk20 desktopfileutils glib20 libglade2
USE_ICONV=	yes
USE_XORG=	x11 xv xext xxf86vm xtst
USE_SDL=	sdl
USE_GL=	gl

MAN1=	pcsx.1
PORTDOCS=	ChangeLog README

.include <bsd.port.pre.mk>

# XXX
# dfxvideo plugin seems buggy, remove it in future updates ?

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--enable-dynarec=x86_64
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

# Extract dfbinimage2 plugin
post-extract:
	@(cd ${WRKSRC} && ${TAR} -xjf ${DISTDIR}/pcsx-df-1.10-plugin-dfbinimage2${EXTRACT_SUFX})

# Add ${PREFIX} to plugins' lookup directories
post-patch:
	@${SED} -i.bak "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/gui/LnxMain.c

pre-configure:
	@(cd ${WRKSRC} && ${AUTORECONF} -fi)

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@-update-desktop-database

.include <bsd.port.post.mk>
