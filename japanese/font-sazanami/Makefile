# New ports collection makefile for:	Sazanami TrueType fonts
# Date created:		19 June 2004
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	sazanami-ttf
PORTVERSION=	20040629
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	efont/10087
DISTNAME=	${PORTNAME:S/-ttf$//}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Free Japanese TrueType fonts named 'Sazanami'

USE_X_PREFIX=	yes
USE_BZIP2=	yes
NO_BUILD=	yes

FONTSDIR=	lib/X11/fonts/TrueType
LOCALFONTSDIR=	share/fonts
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR} \
		LOCALFONTSDIR=${LOCALBASE}/${LOCALFONTSDIR}

WRKSRC=		${WRKDIR}/sazanami-${PORTVERSION}

DOC_FILES=	README \
		doc/oradano/README.txt doc/misaki/misakib8.txt \
		doc/mplus/LICENSE_J doc/shinonome/LICENSE \
		doc/ayu/README.txt doc/kappa/README

do-install:
.if !exists(${PREFIX}/${FONTSDIR})
	@${ECHO} "*********************************************************"
	@${ECHO} "Please add ${PREFIX}/${FONTSDIR} to your font path"
	@${ECHO} "and load 'xtt' module in /etc/XF86Config."
	@${ECHO} "*********************************************************"
	${MKDIR} ${PREFIX}/${FONTSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/sazanami-gothic.ttf \
			${WRKSRC}/sazanami-mincho.ttf \
			${FILESDIR}/fonts.dir.sazanami \
			${FILESDIR}/fonts.alias.sazanami \
			${PREFIX}/${FONTSDIR}
	${MKDIR} ${LOCALBASE}/${LOCALFONTSDIR}/TrueType
	${LN} -s -f \
		${PREFIX}/${FONTSDIR}/sazanami-gothic.ttf \
		${LOCALBASE}/${LOCALFONTSDIR}/TrueType/sazanami-gothic.ttf
	${LN} -s -f \
		${PREFIX}/${FONTSDIR}/sazanami-mincho.ttf \
		${LOCALBASE}/${LOCALFONTSDIR}/TrueType/sazanami-mincho.ttf
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for F in ${DOC_FILES:Mdoc/*}
	${MKDIR} ${DOCSDIR}/${F:S,^doc/,,:H}
	${INSTALL_DATA} ${WRKSRC}/${F} ${DOCSDIR}/${F:S,^doc/,,:H}
.endfor
.for F in ${DOC_FILES:Ndoc/*}
	${INSTALL_DATA} ${WRKSRC}/${F} ${DOCSDIR}
.endfor
.endif
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
