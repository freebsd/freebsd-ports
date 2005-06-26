# New ports collection makefile for:	KDE SDK
# Date created:				2 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdesdk
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Software Development Kit

LIB_DEPENDS=	db4:${PORTSDIR}/databases/db4 \
		svn_client-1.0:${PORTSDIR}/devel/subversion

CONFLICTS=	umbrello-[0-9]* kcachegrind-[0-9]*

USE_KDEBASE_VER=3
PREFIX=		${KDE_PREFIX}

USE_PERL5=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

CONFIGURE_ARGS+=--with-db-include-dir=/usr/local/include/db4 \
		--with-db-lib-dir=/usr/local/lib --with-db-name=db4 \
		--with-apr-config=${LOCALBASE}/bin/apr-1-config \
		--with-apu-config=${LOCALBASE}/bin/apu-1-config

MAN1=		cervisia.1 cvsblame.1 cvscheck.1 cvsversion.1 includemocs.1 kde-build.1 noncvslist.1

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WITH_OPTIONAL_DEPENDS)
	@${ECHO_MSG}
	@${ECHO_MSG} "You may define WITH_OPTIONAL_DEPENDS (make WITH_OPTIONAL_DEPENDS=YES)"
	@${ECHO_MSG} "to automatically build the suggested programs to complement kdesdk3."
	@${ECHO_MSG}
.endif

# callgrind is optional. It depends on valgrind, which is i386 only.
.if defined(WITH_OPTIONAL_DEPENDS) && ${ARCH} == "i386"
RUN_DEPENDS+=	callgrind:${PORTSDIR}/devel/callgrind
.endif

post-patch:
# Breakage might be caused by security/heimdal's broken fnmatch.h
	@${REINPLACE_CMD} -e 's|<\(fnmatch.h\)>|"/usr/include/\1"|' \
		${WRKSRC}/cervisia/stringmatcher.cpp

.include <bsd.port.post.mk>
