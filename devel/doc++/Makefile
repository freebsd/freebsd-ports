# New ports collection makefile for:	DOC++
# Date created:		20 Dec 1998
# Whom:			Ruslan@Shevchenko.Kiev.UA
#
# $FreeBSD$
#

PORTNAME=	doc++
PORTVERSION=	3.4.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	docpp

MAINTAINER=	Ruslan@Shevchenko.Kiev.UA
COMMENT=	Javadoc style C++ documentatation system

.if defined(WITH_GHOSTSCRIPT_AFPL) && ${WITH_GHOSTSCRIPT_AFPL} == yes
GSPORT?=	print/ghostscript-afpl
.else
GSPORT?=	print/ghostscript-gnu
.endif

RUN_DEPENDS=	tex:${PORTSDIR}/print/teTeX \
		gs:${PORTSDIR}/${GSPORT} \
		anytopnm:${PORTSDIR}/graphics/netpbm

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

ADDITIONAL_DOCS=	ClassGraph.class \
			ClassGraphPanel.class \
			ClassLayout.class \
			CommonBase.html \
			CommandLineOptions.html \
			ConfigurationFile.html \
			Derived_Class.html \
			Example.html \
			FileInclusion.html \
			FrequentlyAskedQuestions.html \
			General.html \
			GeneralInformations.html \
			HIER.html \
			HIERjava.html \
			InstallationInstructions.html \
			Intermediate.html \
			Introduction.html \
			ManualEntries.html \
			ManualEntryFields.html \
			NavigatorButton.class \
			Quickstart.html \
			ReferenceManual.html \
			Structure.html \
			Tags.html \
			TextFormatting.html \
			Usage.html \
			function.html \
			icon1.gif \
			icon2.gif \
			index.html \
			supportedHTMLmacros.html \
			supportedTeXmacros.html \
			toc.html

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for i in $(ADDITIONAL_DOCS); do \
		${INSTALL_MAN} ${WRKSRC}/doc/manual/html/$$i ${DOCSDIR} ;\
	done
.endif

.include <bsd.port.mk>
