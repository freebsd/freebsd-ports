# New ports collection makefile for:	unadf
# Date created:				1 October 2000
# Whom:					Per Wigren
#
# $FreeBSD$
#

PORTNAME=	unadf
PORTVERSION=	0.7.12
CATEGORIES=	archivers
MASTER_SITES=	http://lclevy.free.fr/adflib/
DISTNAME=	adflib-${DISTVERSION}

MAINTAINER=	uffe@uffe.org
COMMENT=	Extracts files from .adf-files used by Amiga emulators

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes

MAKE_JOBS_UNSAFE=	yes

USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader automake

#
# args below adapted from adflib: autogen.sh
#
LIBTOOLIZE_ARGS=--copy --force
AUTOMAKE_ARGS=	--add-missing

#
# ports/aclocal workaround:
#
# aclocal only scans version-specific dir: ${LOCALBASE}/share/aclocal-<version>/
# hence aclocal does not find 3rd party m4 files (libtool.m4 etc)
# http://www.freebsd.org/cgi/query-pr.cgi?ports/98435
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal

PLIST_FILES=	bin/unadf

DOCS=		API.txt api_device.html api_dir.html api_env.html api_file.html \
		api_index.html api_native.html api_salv.html api_volume.html version0.7.9d_gary.txt

FAQS=		FAQ/adf_info.html FAQ/adf_info.txt FAQ/adf_info_V0_9.txt

FAQSIMGS=	FAQ/image/adf_dir.gif FAQ/image/adf_file.gif

PORTDOCS=	*

# XXX: work around an issue with automake-1.13 erroring out on a
#      non-existent m4 directory before libtoolize creates it
pre-configure::
	@${MKDIR} ${WRKSRC}/m4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/examples/unadf ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
	${MKDIR} ${DOCSDIR}/FAQ
.for i in ${FAQS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}/FAQ
.endfor
	${MKDIR} ${DOCSDIR}/FAQ/image
.for i in ${FAQSIMGS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}/FAQ/image
.endfor
.endif

.include <bsd.port.mk>
