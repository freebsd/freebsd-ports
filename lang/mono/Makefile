# New ports collection makefile for:   mono
# Date created:        22 July 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $Id: Makefile,v 1.22 2005/05/16 03:43:07 mezz7 Exp $
# $FreeBSD$
#

PORTNAME=	mono
PORTVERSION=	1.1.7
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	http://www.go-mono.com/sources/mono-1.1/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	An open source implementation of .NET Development Framework

CONFLICTS=	mono-devel-[0-9]* mono-svn-[0-9]*

USE_REINPLACE=	yes
USE_BISON=	yes
USE_GNOME=	gnomehack glib20
USE_GMAKE=	yes
LIBTOOLFILES=	configure libgc/configure
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--program-transform-name=\'\' \
		--with-gc=included \
		--with-tls=pthread

MAN1=		cert2spc.1 certmgr.1 chktrust.1 cilc.1 disco.1 dtd2xsd.1 \
		gacutil.1 genxs.1 ilasm.1 jay.1 macpack.1 makecert.1 mcs.1 \
		mint.1 mkbundle.1 mono-service.1 mono.1 monoburg.1 monodis.1 \
		monop.1 monostyle.1 oldmono.1 permview.1 prj2make.1 secutil.1 \
		setreg.1 signcode.1 sn.1 soapsuds.1 sqlsharp.1 wsdl.1 xsd.1
MAN5=		mono-config.5

ONLY_FOR_ARCHS=	i386

MAKE_ENV=MONO_SHARED_DIR=${WRKDIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=	Does not work on 4.X and 5.X before 503000
.endif

# ttyname_r(3) patch
.if ${OSVERSION} < 600028
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-support_mph.h
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/mono/metadata/assembly.c

pre-su-install:
	${MKDIR} ${X11BASE}/lib/mono/gac

.include <bsd.port.post.mk>
