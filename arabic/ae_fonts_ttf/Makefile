# New ports collection makefile for: ae_fonts1_ttf
# Date created:        August 22 2003
# Whom:                Samy Al Bahra <samy@kerneled.com>
#
# $FreeBSD$
#

PORTNAME=		ae_fonts1_ttf
PORTVERSION=		1.1
CATEGORIES=		arabic x11-fonts
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	arabeyes
DISTNAME=		ae_fonts1_ttf_${PORTVERSION}

MAINTAINER=	samy@kerneled.org
COMMENT=	A collection of truetype Arabic fonts created by Arabeyes.org

BUILD_DEPENDS=	ttmkfdir:${PORTSDIR}/x11-fonts/ttmkfdir

USE_X_PREFIX=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/ae_fonts1-${PORTVERSION}

.if !defined(WITHOUT_AAHS)
FONTS=	AAHS
.endif

.if !defined(WITHOUT_AGA)
FONTS+=	AGA
.endif

.if !defined(WITHOUT_FS)
FONTS+=	FS
.endif

.if !defined(WITHOUT_KASR)
FONTS+=	Kasr
.endif

.if !defined(WITHOUT_MCS)
FONTS+=	MCS
.endif

.if !defined(WITHOUT_SHMOOKH)
FONTS+=	Shmookh
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "*****************************************************"
	@${ECHO_MSG} "The following make variables can be set to"
	@${ECHO_MSG} "exclude certain font sets:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITHOUT_AAHS    - do not install the AAHS font set"
	@${ECHO_MSG} "WITHOUT_AGA     - do not install the AGA font set"
	@${ECHO_MSG} "WITHOUT_FS      - do not install the FS font set"
	@${ECHO_MSG} "WITHOUT_KASR    - do not install the Kasr font set"
	@${ECHO_MSG} "WITHOUT_MCS     - do not install the MCS font set"
	@${ECHO_MSG} "WITHOUT_SHMOOKH - do not install the Shmookh font set"
	@${ECHO_MSG} "*****************************************************"
	@${ECHO_MSG} ""

do-build:
.for i in ${FONTS}
	@ttmkfdir -c -d ${WRKSRC}/${i} > ${WRKSRC}/${i}/fonts.dir
.endfor

do-install:
.for i in ${FONTS}
	@${MKDIR} ${PREFIX}/lib/X11/fonts/ae_fonts1/${i}
	@${INSTALL_DATA} ${WRKSRC}/${i}/* ${PREFIX}/lib/X11/fonts/ae_fonts1/${i}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} "s|X11BASE|${X11BASE}|g" \
		| ${SED} "s|PORTNAME|ae_fonts1|g"

.include <bsd.port.mk>
