# New ports collection makefile for:	p5-bioperl-devel
# Date created:		13 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bioperl
PORTVERSION=	0.9.0
CATEGORIES=	biology perl5
MASTER_SITES=	ftp://bioperl.org/pub/DIST/ \
		http://bioperl.org/Core/Latest/
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-devel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	wjv@FreeBSD.org

# These are all run-time dependencies, but listing them in ${BUILD_DEPENDS}
# prevents a flood of build-time warnings.
BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Ace.pm:${PORTSDIR}/biology/p5-AcePerl \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTTP/Request/Common.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Node.pm:${PORTSDIR}/textproc/p5-XML-Node \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Parser/PerlSAX.pm:${PORTSDIR}/textproc/p5-libxml \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Twig.pm:${PORTSDIR}/textproc/p5-XML-Twig \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES
NO_LATEST_LINK=	"Unstable development version."

.if defined(WITH_CORBA)
WITH_CORBA_CLIENT=	YES
WITH_CORBA_SERVER=	YES
.endif

EXT_VERSION=	0.6
CORBA_CLIENT_VERSION=	0.2
CORBA_SERVER_VERSION=	0.2
GUI_VERSION=	0.7
DISTFILES+=	bioperl-ext-${EXT_VERSION}${EXTRACT_SUFX}
EXT_WRKSRC=	${WRKDIR}/bioperl-ext-06/Bio/Ext/Align

.if defined(WITH_CORBA_CLIENT)
BUILD_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/CORBA/ORBit.pm:${PORTSDIR}/devel/p5-ORBit
RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/CORBA/ORBit.pm:${PORTSDIR}/devel/p5-ORBit
.endif
.if defined(WITH_CORBA_SERVER)
BUILD_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/CORBA/ORBit.pm:${PORTSDIR}/devel/p5-ORBit
RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/CORBA/ORBit.pm:${PORTSDIR}/devel/p5-ORBit
.endif
.if defined(WITH_GUI)
RUN_DEPENDS+=	ptksh:${PORTSDIR}/x11-toolkits/p5-Tk
.endif

.for ext in CORBA_CLIENT CORBA_SERVER GUI
.if defined(WITH_${ext})
EXTLIST+=	${ext}
DISTFILES+=	bioperl-${ext:L:S/_/-/}-${${ext}_VERSION}${EXTRACT_SUFX}
${ext}_WRKSRC=	${WRKDIR}/bioperl-${ext:L:S/_/-/}
PLIST_${ext}=	""
.else
PLIST_${ext}=	"@comment "
.endif
PLIST_SUB+=	PLIST_${ext}=${PLIST_${ext}}
.endfor

.include <bsd.port.pre.mk>

# Include the (extremely) long list of manpages from a separate file:
.include "${FILESDIR}/Makefile.man"
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-fetch:
.if !defined(BATCH) && (!defined(WITH_CORBA_CLIENT) || \
    !defined(WITH_CORBA_SERVER) || !defined(WITH_GUI))
	@ ${CAT} ${FILESDIR}/ext.msg
.endif

post-configure:
	@ cd ${EXT_WRKSRC} && \
	  ${SETENV} ${CONFIGURE_ENV} \
	  ${PERL5} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

.for ext in ${EXTLIST}
	@ cd ${${ext}_WRKSRC} && \
	  ${PERL5} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
.endfor

post-build:
	@ cd ${EXT_WRKSRC} && \
	  ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
.for ext in ${EXTLIST}
	@ cd ${${ext}_WRKSRC} && ${SETENV} ${MAKE_ENV} \
	  ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
.endfor

post-install:
	@ cd ${EXT_WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
	  ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
.for ext in ${EXTLIST}
	@ cd ${${ext}_WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
	  ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
.endfor

.include <bsd.port.post.mk>
