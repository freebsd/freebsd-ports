# New ports collection makefile for:	DOC++
# Date created:		20 Dec 1998
# Whom:			Ruslan@Shevchenko.Kiev.UA
#
# $FreeBSD$
#

PORTNAME=	doc++
PORTVERSION=	3.4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.linuxsupportline.com/~doc++/
MASTER_SITE_SUBDIR=	apps/doctools

MAINTAINER=	Ruslan@Shevchenko.Kiev.UA

RUN_DEPENDS=	tex:${PORTSDIR}/print/teTeX \
		gs:${PORTSDIR}/print/ghostscript5 \
		anytopnm:${PORTSDIR}/graphics/netpbm

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

ADDITIONAL_DOCS=	ClassGraph.class \
			ClassGraphPanel.class \
			ClassLayout.class \
			CommonBase.html \
			Derived_Class.html \
			Example.html \
			FileInclusion.html \
			FrequentlyAskedQuestions.html \
			General.html \
			HIER.html \
			HIERjava.html \
			InstallationInstructions.html \
			Intermediate.html \
			Introduction.html \
			ManualEntries.html \
			NavigatorButton.class \
			Quickstart.html \
			ReferenceManual.html \
			Structure.html \
			TextFormatting.html \
			Usage.html \
			down.gif \
			function.html \
			icon1.gif \
			icon2.gif \
			index.html \
			logo.gif \
			supportedHTMLmacros.html \
			supportedTeXmacros.html 

post-install:
.if !defined(NOPORTSDOCS)
	${MKDIR} ${PREFIX}/share/doc/doc++
	for i in $(ADDITIONAL_DOCS); do \
            ${INSTALL_MAN} ${WRKSRC}/doc/manual/html/$$i ${PREFIX}/share/doc/doc++ ;\
	done
.endif

.include <bsd.port.mk>
