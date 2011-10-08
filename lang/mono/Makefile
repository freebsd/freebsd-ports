# New ports collection makefile for:   mono
# Date created:        22 July 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mono
PORTVERSION=	2.10.6
CATEGORIES=	lang
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	An open source implementation of .NET Development Framework

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
    		bash:${PORTSDIR}/shells/bash

USE_BZIP2=	yes
USE_BISON=	build
USE_GNOME=	gnomehack glib20
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
MAKE_JOBS_UNSAFE=yes

# Moonlight is installed as part of www/moonlight
CONFIGURE_ARGS=	--with-moonlight=no

# Set location for .wapi creation.
MONO_SHARED_DIR=${WRKDIR}

# LC_ALL is set in order to work around issues people are having when using
# other languages.  This has shown itself in build fails and possibly other
# strange crashes.
MAKE_ENV=	MONO_SHARED_DIR="${MONO_SHARED_DIR}" \
		LC_ALL=C

ONLY_FOR_ARCHS=	i386 amd64 ppc

MAN1=		al.1 ccrewrite.1 cert2spc.1 certmgr.1 chktrust.1 cilc.1 \
		csharp.1 disco.1 dtd2xsd.1 gacutil.1 genxs.1 httpcfg.1 \
		ilasm.1 lc.1 macpack.1 makecert.1 mconfig.1 mcs.1 \
		mdassembler.1 mdoc-assemble.1 mdoc-export-html.1 \
		mdoc-export-msxdoc.1 mdoc-update.1 mdoc-validate.1 mdoc.1 \
		mdvalidater.1 mkbundle.1 mono-api-info.1 mono-cil-strip.1 \
		mono-configuration-crypto.1 mono-service.1 mono-shlib-cop.1 \
		mono-xmltool.1 mono.1 monodis.1 monodocer.1 monodocs2html.1 \
		monolinker.1 monop.1 mozroots.1 pdb2mdb.1 permview.1 \
		prj2make.1 resgen.1 secutil.1 setreg.1 sgen.1 signcode.1 sn.1 \
		soapsuds.1 sqlsharp.1 wsdl.1 xbuild.1 xsd.1
MAN5=		mdoc.5 mono-config.5

.include <bsd.port.pre.mk>

pre-everything::
	@${CAT} ${PKGMESSAGE}

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/bin/bash|#!/bin/sh|g' \
		${WRKSRC}/mcs/class/Managed.Windows.Forms/build-csproj \
		${WRKSRC}/mcs/class/Managed.Windows.Forms/build-csproj2k5 \
		${WRKSRC}/mcs/class/Mono.WebBrowser/build-csproj2k5
	@${FIND} ${WRKSRC} -name '*.sh' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^#!/bin/bash|#!/bin/sh|g'

tests: build
	@${ECHO_MSG} "===> Running mono regression tests"
	@(cd ${WRKSRC}/mono/tests && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} Makefile ${MAKE_ARGS} test)

post-configure:
	@${REINPLACE_CMD} -e 's|share\/man|man|g' \
		${WRKSRC}/mcs/jay/Makefile

.include "${PORTSDIR}/lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
