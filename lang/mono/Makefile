# New ports collection makefile for:   mono
# Date created:        22 July 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.94 2007/10/03 01:34:13 killfill Exp $
#

PORTNAME=	mono
PORTVERSION=	1.2.5.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	bsd-sharp@googlegroups.com
COMMENT=	An open source implementation of .NET Development Framework

CONFLICTS=	mono-devel-[0-9]* mono-svn-[0-9]*

USE_BZIP2=	yes
USE_BISON=	yes
USE_GNOME=	gnomehack glib20
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
LIBTOOLFILES=	configure libgc/configure
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--program-transform-name=\'\' \
		--with-gc=included \
		--with-tls=pthread \
		--mandir=${PREFIX}/man
MAKE_ARGS=	EXTERNAL_MCS=false

# Set location for .wapi creation.
MONO_SHARED_DIR=${WRKDIR}

# LC_ALL is set in order to work around issues people are having when using
# other languages.  This has shown itself in build fails and possibly other
# strange crashes.
MAKE_ENV=	LC_ALL=C

# Removed amd64 arch because builds are exhibiting semaphore problems on
# pointyhat runs causing failure to build.
ONLY_FOR_ARCHS= i386 amd64

MAN1=		al.1 cert2spc.1 certmgr.1 chktrust.1 cilc.1 disco.1 dtd2xsd.1 \
		gacutil.1 genxs.1 ilasm.1 jay.1 macpack.1 makecert.1 mcs.1 \
		mint.1 mkbundle.1 mono-service.1 mono-shlib-cop.1 mono.1 \
		monoburg.1 monodis.1 monop.1 monostyle.1 mozroots.1 oldmono.1 \
		permview.1 prj2make.1 secutil.1 setreg.1 signcode.1 sn.1 \
		soapsuds.1 sqlsharp.1 wsdl.1 xsd.1 mono-xmltool.1 sgen.1 \
		httpcfg.1 vbnc.1 resgen.1 monolinker.1
MAN5=		mono-config.5

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
USE_FAM=	yes
.endif

pre-everything::
	@${CAT} ${PKGMESSAGE}

.if ${OSVERSION} < 503000
IGNORE=	does not work on 4.X and 5.X before 503000
.endif

# ttyname_r(3) patch
.if ${OSVERSION} < 600028
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-support_mph.h
.endif

.if exists(${LOCALBASE}/lib/libfam.so)
USE_FAM=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure ${WRKSRC}/libgc/configure
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g ; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' \
		${WRKSRC}/mcs/tools/mkbundle/mkbundle.cs
	@${REINPLACE_CMD} -e 's|libgamin-1.so.0|libgamin-1.so.1|g' \
		${WRKSRC}/mcs/class/System/System.IO/FAMWatcher.cs
	@${REINPLACE_CMD} -e 's|^#!/bin/bash|#!/bin/sh|g' \
		${WRKSRC}/mcs/class/Managed.Windows.Forms/build-csproj \
		${WRKSRC}/mcs/class/Managed.Windows.Forms/build-csproj2k5

.if ${OSVERSION} >= 700000 && ${OSVERSION} < 800000
	@${REINPLACE_CMD} -e 's|freebsd6|freebsd7|g' \
		${WRKSRC}/configure ${WRKSRC}/libgc/configure
.elif ${OSVERSION} >= 800000
	@${REINPLACE_CMD} -e 's|freebsd6|freebsd8|g' \
		${WRKSRC}/configure ${WRKSRC}/libgc/configure
.endif

tests: build
	@${ECHO_MSG} "===> Running mono regression tests"
	@(cd ${WRKSRC}/mono/tests && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} Makefile ${MAKE_ARGS} test)

post-configure:
	@${REINPLACE_CMD} -e 's|share\/man|man|g' \
		${WRKSRC}/mcs/jay/Makefile

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
