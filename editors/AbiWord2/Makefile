# New ports collection makefile for:    AbiWord
# Date created:         3 Mar 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

# Note: this port cannot be built when the textproc/mswordview port is
# already installed, due to header file conflicts and the very broken
# AbiWord build system.

PORTNAME=	AbiWord
PORTVERSION=	0.9.6.1
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.abisource.com/downloads/Version-${PORTVERSION}/lf/
MASTER_SITE_SUBDIR=	abiword
DISTNAME=	abiword-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

# unzip is needed during the installation process
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		giconv.2:${PORTSDIR}/converters/libiconv \
		psiconv.7:${PORTSDIR}/converters/psiconv

DIST_SUBDIR=	AbiWord

WRKSRC=		${WRKDIR}/${DISTNAME}/abi

USE_AUTOMAKE=	yes
USE_GMAKE=	yes
USE_GTK=	yes
AUTOMAKE=	${WRKSRC}/autogen.sh && ${FIXME}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgiconv"
MAKEFILE=	GNUmakefile
FIXME=		find ${WRKSRC} -name GNUmakefile.in | xargs ${PERL} -pi -e \
		    's|\$$\(libdir\)/\@PACKAGE\@|\$$\(datadir\)/\@PACKAGE\@|g ; \
		     s|\@DEFS\@|-I${WRKSRC}/../libiconv/include \@DEFS\@|g'

post-patch:
	@${RM} ${WRKSRC}/user/wp/strings/*.orig

pre-configure:
	@cd ${WRKSRC} && ${TOUCH} NEWS README AUTHORS ChangeLog
	@cd ${WRKSRC}/ac-helpers && ${RM} -f install-sh mkinstalldirs missing
	@${RM} -f ${WRKSRC}/configure.ac

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
