# New ports collection makefile for:	unfonts-ttf
# Date created:		27 September 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	unfonts
PORTVERSION=	20030907
PORTREVISION=	1
CATEGORIES=	korean x11-fonts
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~perky/distfiles/
MASTER_SITE_SUBDIR=	perky
PKGNAMESUFFIX=	-ttf
DISTNAME=	UnFonts${PKGNAMESUFFIX}-${PORTVERSION}

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	UnFonts-ooofontname-patch.tar.gz

MAINTAINER=	perky@FreeBSD.org
COMMENT=	GPL'd Korean TrueType Fonts by UN Koaunghi

PATCH_DEPENDS=	bspatch:${PORTSDIR}/misc/bsdiff

USE_X_PREFIX=	yes
USE_BZIP2=	yes
NO_BUILD=	yes
FONTDIR=	${PREFIX}/lib/X11/fonts/TrueType
FONTLIST=	UnBatang UnBatangBold UnBom UnDotum UnDotumBold UnGraphic \
		UnGungseo UnPen UnPenheulim UnPilgi UnPilgiBold UnShinmun \
		UnYetgul

post-extract:
	${TAR} -C ${WRKSRC} -xzf ${DISTDIR}/UnFonts-ooofontname-patch.tar.gz

do-patch:
	cd ${WRKSRC} && for FONTNAME in ${FONTLIST}; do \
		if [ -f $$FONTNAME-ooofontname.diff ]; then \
			${CP} $$FONTNAME.ttf $$FONTNAME.orig.ttf; \
			${LOCALBASE}/bin/bspatch $$FONTNAME.orig.ttf \
				$$FONTNAME.ttf $$FONTNAME-ooofontname.diff; \
		fi; \
	done

do-install:
	${MKDIR} ${FONTDIR}
.for FONTNAME in ${FONTLIST}
	${INSTALL_DATA} ${WRKSRC}/${FONTNAME}.ttf ${FONTDIR}
.endfor

.include <bsd.port.mk>
