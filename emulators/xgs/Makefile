# New ports collection makefile for:	xgs
# Date created:		2nd May, 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
#
# $FreeBSD$
#
# This is the stable release of the xgs emulator. Sound support is
# currently broken.

PORTNAME=	xgs
PORTVERSION=	0.50
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.inwards.com/xgs/ \
		http://www.inwards.com/xgs/2mg/
DISTFILES=	xgs050.tgz ROM01.ZIP
EXTRACT_ONLY=	xgs050.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apple IIGS emulator stable release

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

DIST_SUBDIR=	xgs
RESTRICTED=	"xgs.rom copyright is owned by Apple and cannot be distributed"

# Source building
#
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x

# Directories etc...
#
XGS_DIR=	${PREFIX}/share/xgs
XGS_DOC=	${PREFIX}/share/doc/xgs
MYPORTDOCS=	CHANGES.TXT COMPAT.TXT INSTALL.TXT IWM-DOC.TXT TODO.TXT \
		XGS-FAQ.TXT

post-extract:
	unzip -L -qq ${_DISTDIR}/ROM01.ZIP -d ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/xgs.rom ${XGS_DIR}
	${INSTALL_DATA} -m 666 /dev/null ${XGS_DIR}/xgs.ram
.if !defined(NOPORTDOCS)
	@${MKDIR} ${XGS_DOC}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${XGS_DOC}
.endfor
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${XGS_DOC}
.endif

.include <bsd.port.mk>
