# New ports collection makefile for:   cedet
# Date created:                2004-02-28
# Whom:                        Dryice Liu
#
# $FreeBSD$
#

PORTNAME=	cedet
PORTVERSION=	1.0.p7
CATEGORIES=	devel elisp
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.0pre7
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}-1.0pre7

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Collection of Emacs Development Environment Tools

USE_EMACS=		yes
MAKE_JOBS_UNSAFE=	yes
USE_GMAKE=		yes

CEDET_LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

INFO=		bovine cogre ede eieio grammar-fw semantic \
		semantic-appdev semantic-langdev semantic-user \
		wisent speedbar-cedet srecode

SEMANTIC_ELISP_SUBDIRS=	bovine wisent
SEMANTIC_INFOS=	bovine.info grammar-fw.info semantic-appdev.info \
		semantic-langdev.info semantic-user.info semantic.info \
		wisent.info

CONFLICTS=	eieio-[0-9]* semantic-[0-9]* speedbar-[0-9]*

pre-build:
#cleanup info
	${RM} -f ${WRKSRC}/ede/ede.info
	${RM} -f ${WRKSRC}/speedbar/speedbar.info
.for i in ${SEMANTIC_INFOS}
	${RM} -f ${WRKSRC}/semantic/doc/${i}
.endfor
	${RM} -f ${WRKSRC}/cogre/cogre.info
	${RM} -f ${WRKSRC}/eieio/eieio.info

do-install:
	${MKDIR} ${CEDET_LISPDIR}

# cogre
	${MKDIR} ${CEDET_LISPDIR}/cogre
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/cogre/${i} ${CEDET_LISPDIR}/cogre
.endfor
	${INSTALL_DATA} ${WRKSRC}/cogre/cogre.info ${PREFIX}/info

# common
	${MKDIR} ${CEDET_LISPDIR}/common
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/common/${i} ${CEDET_LISPDIR}/common
.endfor
	${MKDIR} ${CEDET_LISPDIR}/common/icons
.for i in *.xpm
	${INSTALL_DATA} ${WRKSRC}/common/icons/${i} ${CEDET_LISPDIR}/common/icons
.endfor

# ede
	${MKDIR} ${CEDET_LISPDIR}/ede
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/ede/${i} ${CEDET_LISPDIR}/ede
.endfor
	${INSTALL_DATA} ${WRKSRC}/ede/ede.info ${PREFIX}/info

# eieio
	${MKDIR} ${CEDET_LISPDIR}/eieio
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/eieio/${i} ${CEDET_LISPDIR}/eieio
.endfor
	${INSTALL_DATA} ${WRKSRC}/eieio/eieio.info ${PREFIX}/info

# semantic
	${MKDIR} ${CEDET_LISPDIR}/semantic
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/semantic/${i} ${CEDET_LISPDIR}/semantic
.endfor

.for j in ${SEMANTIC_ELISP_SUBDIRS}
	${MKDIR} ${CEDET_LISPDIR}/semantic/${j}
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/semantic/${j}/${i} ${CEDET_LISPDIR}/semantic/${j}
.endfor
.endfor

.for i in ${SEMANTIC_INFOS}
	${INSTALL_DATA} ${WRKSRC}/semantic/doc/${i} ${PREFIX}/info
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/semantic/semanticdb.sh ${PREFIX}/bin

# speedbar (Emacs-22 have own but version oldes than req in cedet)
	${MKDIR} ${CEDET_LISPDIR}/speedbar

.for i in *.el *.elc *.xpm
	${INSTALL_DATA} ${WRKSRC}/speedbar/${i} ${CEDET_LISPDIR}/speedbar
.endfor

	${INSTALL_DATA} ${WRKSRC}/speedbar/speedbar-cedet.info ${PREFIX}/info

# srecode
	${MKDIR} ${CEDET_LISPDIR}/srecode
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/srecode/${i} ${CEDET_LISPDIR}/srecode
.endfor
	${MKDIR} ${CEDET_LISPDIR}/srecode/templates
.for i in *.srt
	${INSTALL_DATA} ${WRKSRC}/srecode/templates/${i} ${CEDET_LISPDIR}/srecode/templates
.endfor
	${INSTALL_DATA} ${WRKSRC}/srecode/srecode.info ${PREFIX}/info

#contrib
	${MKDIR} ${CEDET_LISPDIR}/contrib
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/contrib/${i} ${CEDET_LISPDIR}/contrib
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
