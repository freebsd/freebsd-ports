# New ports collection makefile for:	emboss
# Date created:		31 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	emboss
PORTVERSION=	2.10.0
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.uk.embnet.org/pub/EMBOSS/ \
		ftp://ftp.es.embnet.org/pub/software/emboss/EMBOSS/ \
		ftp://ftp.ebi.ac.uk/pub/software/unix/EMBOSS/
DISTNAME=	${PORTNAME:U}-${PORTVERSION}
DISTFILES=	${PORTNAME:U}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A collection of open source tools for genetic sequence analysis

BUILD_DEPENDS=	clustalw:${PORTSDIR}/biology/clustalw \
		primer3:${PORTSDIR}/biology/primer3
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
		png.5:${PORTSDIR}/graphics/png

CONFLICTS=	nss-* qmail-ldap2-* digest-*

USE_SUBMAKE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_XLIB=	yes
USE_MOTIF=	yes
USE_REINPLACE=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:U}
DATADIR=	${PREFIX}/share/${PORTNAME:U}

DOC_DIRS=	doc/manuals doc/tutorials doc/programs/text doc/programs/html
CONFIG_FILE=	${WRKSRC}/emboss/emboss.default.template

post-patch:
.if !defined(NOPORTDOCS)
.for DIR in ${DOC_DIRS}
	${REINPLACE_CMD} -e \
	  's#$$(prefix)/share/$$(PACKAGE)/doc#$$(datadir)/doc/$$(PACKAGE)#' \
	  ${WRKSRC}/${DIR}/Makefile.in
.endfor
.endif

post-install:
	@ cd ${WRKSRC} && \
	${SED} -e 's#%%PREFIX%%#${PREFIX}#' \
	${CONFIG_FILE} > ${PREFIX}/etc/emboss.default.sample && \
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/etc/emboss.default.sample
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#' ${.CURDIR}/pkg-message > ${PKGMESSAGE}
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
