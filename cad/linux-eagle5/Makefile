# Created by: Michael Durian <durian@shadetreesoftware.com>
# $FreeBSD$

PORTNAME=	eagle5
PORTVERSION=	${EAGLEVERSION}
PORTREVISION=	4
CATEGORIES=	cad linux
MASTER_SITES=	ftp://ftp.cadsoft.de/eagle/program/${EAGLEBASEVERSION}/
PKGNAMEPREFIX=	linux-
DISTNAME=	eagle-lin-${EAGLEVERSION}
EXTRACT_SUFX=	.run

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	An easy to use, yet powerful tool for designing printed circuit boards

LICENSE=	Eagle
LICENSE_NAME=	Eagle End User License Agreement
LICENSE_FILE=	${WRKSRC}/doc/license_en.txt
LICENSE_PERMS=	auto-accept

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/${DISTNAME:S/lin-//}

EXTRACT_CMD=	${SED}
EXTRACT_BEFORE_ARGS=	-e '1,/^__DATA__$$/d'
EXTRACT_AFTER_ARGS=	| ${BZCAT} -c 2>/dev/null | ${TAR} -xf -

RESTRICTED=	Usage permitted for non-commercial purposes only
NO_CDROM=	Sale for profit is not permitted
NO_PACKAGE=	Copying the software is only allowed for backup by an individual licensee

EAGLEBASEVERSION=	5.12
EAGLEBUGFIX=	0
EAGLEVERSION=	${EAGLEBASEVERSION}.${EAGLEBUGFIX}

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs jpeg png
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-deinstall pkg-message

DESKTOP_ENTRIES=	"Eagle5" "Tool for designing printed circuit boards" \
			${DATADIR}/ulp/eagle.bmp \
			"eagle" "Development;Electronics;Engineering;" false

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	${INSTALL_MAN} ${STAGEDIR}${DATADIR}/doc/eagle.1 ${STAGEDIR}${PREFIX}/man/man1/eagle.1
	${SED} -e "s:%%DATADIR%%:${DATADIR}:g" ${FILESDIR}/eagle.sh > ${STAGEDIR}${PREFIX}/bin/eagle

.include <bsd.port.mk>
