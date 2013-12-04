# Created by: paulo@isr.uc.pt
# $FreeBSD$

PORTNAME=	povray
PORTVERSION=	3.1g
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.povray.org/pub/povray/%SUBDIR%/ \
		ftp://ftp.mirrorservice.org/sites/ftp.povray.org/pub/povray/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/povray/%SUBDIR%,}
MASTER_SITE_SUBDIR=	Old-Versions/Official-3.1g/Unix
PKGNAMESUFFIX=	31
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}
DISTFILES=	povuni_s.tgz povuni_d.tgz
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	Persistence of Vision Ray Tracer

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=	X11

#
#   I think all of this needs some explanation.
#   The port downloads the MS-DOS source files of POV-Ray 3.1d
#   and the UNIX source files of POV-Ray 3.0 (which need some
#   patching, obviously).  This is necessary because there are
#   no UNIX source files for POV-Ray 3.1.
#

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11
ALL_TARGET=	newxwin
POVBIN=		${BUILD_WRKSRC}/x-povray
.else
ALL_TARGET=	newunix
POVBIN=		${BUILD_WRKSRC}/povray
.endif

MAN1=		${PORTNAME}${PKGNAMESUFFIX}.1

POVLIB=		${PREFIX}/lib/${PORTNAME}${PKGNAMESUFFIX}

BUILD_WRKSRC=	${WRKSRC}/source/unix
MAKEFILE=	makefile

do-install:
	@${MKDIR} ${POVLIB}/allscene
	@${TOUCH} ${POVLIB}/allscene/.bla
	@${INSTALL_PROGRAM} ${POVBIN} ${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}
	@(cd ${WRKSRC}; ${TAR} cpf - include scenes) | \
		(cd ${POVLIB}; ${TAR} xpf -)
	@${INSTALL_DATA} ${WRKSRC}/*.ini ${POVLIB}/
	@${INSTALL_DATA} ${WRKSRC}/*.doc ${POVLIB}/
	@${INSTALL_DATA} ${WRKSRC}/*.txt ${POVLIB}/
	@${INSTALL_DATA} ${WRKSRC}/*.gif ${WRKSRC}/*.xpm ${POVLIB}/
	@${INSTALL_SCRIPT} ${WRKSRC}/allscene.sh ${POVLIB}/
	@${MV} ${WRKSRC}/${PORTNAME}.1 ${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX}.1
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX}.1 ${PREFIX}/man/man1
	@${CHMOD} -R a+rX,og-w ${POVLIB}

post-install:
	@${SH} ${FILESDIR}/script

.include <bsd.port.mk>
