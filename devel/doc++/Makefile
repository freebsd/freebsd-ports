# New ports collection makefile for:	DOC++
# Date created:		20 Dec 1998
# Whom:			Ruslan@Shevchenko.Kiev.UA
#
# $FreeBSD$
#

PORTNAME=	doc++
PORTVERSION=	3.4.10
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	docpp

MAINTAINER=	Ruslan@Shevchenko.Kiev.UA
COMMENT=	Javadoc style C++ documentatation system

RUN_DEPENDS=	tex:${PORTSDIR}/print/teTeX \
		anytopnm:${PORTSDIR}/graphics/netpbm

BROKEN=		Does not correctly use gettext
DEPRECATED=	"${BROKEN}"
EXPIRATION_DATE=2005-09-22

.if defined(WITH_GHOSTSCRIPT_AFPL) && ${WITH_GHOSTSCRIPT_AFPL} == yes
RUN_DEPENDS+=	gs:${PORTSDIR}/print/ghostscript-afpl
.else
RUN_DEPENDS+=	gs:${PORTSDIR}/print/ghostscript-gnu
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CPPFLAGS=-D__GNU_LIBRARY__

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

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for i in ${ADDITIONAL_DOCS}; do \
		${INSTALL_MAN} ${WRKSRC}/doc/manual/html/$$i ${DOCSDIR} ;\
	done
.endif

.include <bsd.port.post.mk>
