# New ports collection makefile for:	emboss
# Date created:		31 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	emboss
PORTVERSION=	3.0.0
CATEGORIES=	biology
MASTER_SITES=	ftp://emboss.open-bio.org/pub/EMBOSS/ \
		ftp://ftp.uk.embnet.org/pub/EMBOSS/ \
		ftp://ftp.es.embnet.org/pub/software/emboss/EMBOSS/ \
		ftp://ftp.ebi.ac.uk/pub/software/unix/EMBOSS/
DISTNAME=	${PORTNAME:U}-${PORTVERSION}
DISTFILES=	${PORTNAME:U}-${PORTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A collection of open source tools for genetic sequence analysis

BUILD_DEPENDS=	clustalw:${PORTSDIR}/biology/clustalw \
		primer3:${PORTSDIR}/biology/primer3
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
		png.5:${PORTSDIR}/graphics/png

CONFLICTS=	qmail-ldap-[0-9]* digest-[0-9]*

PREFIX?=	${LOCALBASE}/emboss
NO_MTREE=	yes
USE_SUBMAKE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
USE_XLIB=	yes
USE_MOTIF=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PREFIX=${PREFIX} DATADIR=${DATADIR}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:U}
DATADIR=	${PREFIX}/share/${PORTNAME:U}

DOC_DIRS=	doc/manuals doc/tutorials doc/programs/text doc/programs/html
CONFIG_FILE=	${WRKSRC}/emboss/emboss.default.template

post-patch:
.if !defined(NOPORTDOCS)
.for DIR in ${DOC_DIRS}
	@ ${REINPLACE_CMD} -e \
	  's#$$(prefix)/share/$$(PACKAGE)/doc#$$(datadir)/doc/$$(PACKAGE)#' \
	  ${WRKSRC}/${DIR}/Makefile.in
.endfor
.endif

pre-install:
	@ ${REINPLACE_CMD} -e 's#%%DATADIR%%#${DATADIR}#' ${CONFIG_FILE}

post-install:
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DATADIR}/emboss.default.template
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
