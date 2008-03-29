# New ports collection makefile for:	VLGothic fotns
# Date created:		31 Oct 2006
# Whom:			NIIMI Satoshi <sa2c@sa2c.net>
#
# $FreeBSD$
#

PORTNAME=	vlgothic
PORTVERSION=	20080327
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://vinelinux.org/~daisuke/vlgothic/
DISTNAME=	VLGothic-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Japanese TrueType fonts named 'VLGothic'

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

WRKSRC=		${WRKDIR}/VLGothic

USE_BZIP2=	yes
NO_BUILD=	yes

PLIST_SUB=	FONTSDIR="${FONTSDIR_REL}"

FONTSDIR=	${PREFIX}/lib/X11/fonts/vlgothic
FONTSDIR_REL=	${FONTSDIR:S,${PREFIX}/,,}

TTF_FILES=	VL-PGothic-Regular.ttf VL-Gothic-Regular.ttf
DOC_FILES=	Changelog LICENSE LICENSE.en LICENSE_E.mplus LICENSE_J.mplus \
		README README.sazanami README_J.mplus

do-install:
	@${MKDIR} ${FONTSDIR}
.for file in ${TTF_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${FONTSDIR}
.endfor
	@${MKDIR} ${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/63-vlgothic.conf \
			${PREFIX}/etc/fonts/conf.d
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}

.include <bsd.port.mk>
