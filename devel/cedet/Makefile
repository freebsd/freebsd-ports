# New ports collection makefile for:   cedet
# Date created:                2004-02-28
# Whom:                        Dryice Liu
#
# $FreeBSD$
#

PORTNAME=	cedet
PORTVERSION=	1.0.b3.b
CATEGORIES=	devel elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://bsdchat.com/dist/dryice/
MASTER_SITE_SUBDIR=	cedet
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}-1.0beta3b

MAINTAINER=	dryice@liu.com.cn
COMMENT=	Collection of Emacs Development Environment Tools

PORTCLASS=	master
EMACS_PORT_NAME?=	emacs21

CEDET_LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

INFO=		bovine cogre ede eieio grammar-fw semantic \
		semantic-appdev semantic-langdev semantic-user \
		wisent speedbar
SEMANTIC_ELISP_SUBDIRS=	bovine wisent
SEMANTIC_INFOS=	bovine.info grammar-fw.info semantic-appdev.info \
		semantic-langdev.info semantic-user.info semantic.info \
		wisent.info

USE_GMAKE=	yes
CONFLICTS=	eieio* semantic* speedbar*

do-install:
	${MKDIR} ${CEDET_LISPDIR}

# cogre
	${MKDIR} ${CEDET_LISPDIR}/cogre
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/cogre/${i} ${CEDET_LISPDIR}/cogre
.endfor
	${INSTALL_DATA} ${WRKSRC}/cogre/cogre.info ${PREFIX}/info
	install-info ${PREFIX}/info/cogre.info ${PREFIX}/info/dir

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
.for i in *.info*
	${INSTALL_DATA} ${WRKSRC}/ede/${i} ${PREFIX}/info
.endfor
	install-info ${PREFIX}/info/ede.info ${PREFIX}/info/dir

# eieio
	${MKDIR} ${CEDET_LISPDIR}/eieio
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/eieio/${i} ${CEDET_LISPDIR}/eieio
.endfor
	${INSTALL_DATA} ${WRKSRC}/eieio/eieio.info ${PREFIX}/info
	install-info ${PREFIX}/info/eieio.info ${PREFIX}/info/dir

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

.for i in *.info*
	${INSTALL_DATA} ${WRKSRC}/semantic/doc/${i} ${PREFIX}/info
.endfor
.for i in ${SEMANTIC_INFOS}
	install-info ${PREFIX}/info/${i} ${PREFIX}/info/dir
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/semantic/semanticdb.sh ${PREFIX}/bin

# speedbar
	${MKDIR} ${CEDET_LISPDIR}/speedbar
.for i in *.el *.elc *.xpm
	${INSTALL_DATA} ${WRKSRC}/speedbar/${i} ${CEDET_LISPDIR}/speedbar
.endfor
	${INSTALL_DATA} ${WRKSRC}/speedbar/speedbar.info ${PREFIX}/info
	install-info ${PREFIX}/info/speedbar.info ${PREFIX}/info/dir

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
