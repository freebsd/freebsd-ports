# New ports collection makefile for:	sun-wtk
# Date created:				Mon 12 Apr 2004 19:42:00 EEST
# Whom:					Panagiotis Astithas <past@noc.ntua.gr>
#
# $FreeBSD$
#

PORTNAME=	wtk
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	sun-
DISTNAME=	j2me_wireless_toolkit-${PORTVERSION:S/./_/}-linux-i386
EXTRACT_SUFX=	.bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sun J2ME Wireless Toolkit

EXTRACT_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip

USE_LINUX=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes
DOWNLOAD_URL=	https://cds.sun.com/is-bin/INTERSHOP.enfinity/WFS/CDS-CDS_Developer-Site/en_US/-/USD/ViewProductDetail-Start?ProductRef=j2me_wireless_toolkit-${PORTVERSION:S/./_/}-oth-JPR@CDS-CDS_Developer

RESTRICTED=	License does not allow redistribution of any kind

SUB_FILES=	pkg-message
APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=You must manually fetch the J2ME WTK self-extracting file for the Linux platform (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} \
	&& dd bs=1024 if=${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		of=${WRKDIR}/j2mewtk-solaris.zip skip=20 2>/dev/null
	@${LOCALBASE}/bin/unzip -qo ${WRKDIR}/j2mewtk-solaris.zip -d ${WRKSRC}
	@${FIND} ${WRKSRC} -type f -exec ${CHMOD} 0644 {} \+
	@${FIND} ${WRKSRC} -type d -exec ${CHMOD} 0755 {} \+
	@${FIND} ${WRKSRC}/bin ! -name '*.jar' -exec ${CHMOD} 0755 {} \;

do-patch:
	@${REINPLACE_CMD} -e "\
		s@javapathtowtk=.*@javapathtowtk=${JAVA_HOME}/bin/@; \
		s@/usr/bin/expr@/bin/expr@g" \
		${WRKSRC}/bin/defaultdevice ${WRKSRC}/bin/emulator \
		${WRKSRC}/bin/ktoolbar ${WRKSRC}/bin/prefs \
		${WRKSRC}/bin/utils ${WRKSRC}/bin/wscompile
	@${MV} ${WRKSRC}/wtklib/Linux ${WRKSRC}/wtklib/FreeBSD
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	@${MKDIR} ${APP_HOME}
	cd "${WRKSRC}" && ${FIND} . \
	  | ${CPIO} -pdmu -R root:wheel "${APP_HOME}"
	@${LN} -sf ${APP_HOME}/bin/ktoolbar ${PREFIX}/bin/ktoolbar

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
