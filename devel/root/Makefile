# New ports collection makefile for:   root
# Date created:        7 April 2004
# Whom:                Simon Lang <slang@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	root
PORTVERSION=	4.00.03
CATEGORIES=	devel science math
MASTER_SITES=	ftp://root.cern.ch/root/
DISTNAME=	${PORTNAME}_v${PORTVERSION}.source

MAINTAINER=	simon@lang-clan.de
COMMENT=	An Object-Oriented Data Analysis Framework

HAS_CONFIGURE=		yes
CONFIGURE_TARGET=	freebsd4
ALL_TARGET=		showbuild skip all
USE_GMAKE=		yes
USE_OPENLDAP=		yes
USE_QT_VER=		3
QT_NONSTANDARD=		yes
USE_XLIB=		yes
USE_XPM=		yes
USE_GL=			yes
USE_REINPLACE=		yes
REINPLACE_ARGS=		-i ""
WRKSRC=			${WRKDIR}/${PORTNAME}

F77?=			f77

# If the related ports are installed you may enable ROOT's support
# for them, too. It *seams* that
#   --enable-asimage   (After Image: ports/graphics/libafterimage)
#   --enable-mysql     (MySQL:       ports/databases/mysql50-client)
#   --enable-pgsql     (PostgreSQL:  ports/databases/postgresql73)
# are working. A know but yet unsolved problem: The support of
# Kerberos 5 needs some patches to ROOT.
# For this port my intention was to use only features that are
# available out of the box on a FreeBSD system running X11/QT.
# A lot of the features are related to software used in high
# energy physics projects. Have a look to the ROOT web page for
# more informations.
CONFIGURE_ARGS=				\
	${CONFIGURE_TARGET}		\
	--prefix=${PREFIX}		\
	--etcdir=${PREFIX}/etc		\
	--mandir=${PREFIX}/man/man1	\
	--disable-afs			\
	--disable-alien			\
	--disable-asimage		\
	--disable-cern			\
	--disable-chirp			\
	--disable-dcache		\
	--enable-exceptions		\
	--enable-explicitlink		\
	--disable-globus		\
	--disable-krb5			\
	--enable-ldap			\
	--disable-mysql			\
	--enable-opengl			\
	--disable-openiv		\
	--disable-pgsql			\
	--disable-pythia		\
	--disable-pythia6		\
	--with-qt-incdir=${QT_PREFIX}/include	\
	--with-qt-libdir=${QT_PREFIX}/lib	\
	--disable-rfio			\
	--disable-rpath			\
	--disable-sapdb			\
	--disable-shadowpw		\
	--enable-shared			\
	--enable-soversion		\
	--disable-srp			\
	--disable-table			\
	--disable-venus

INSTALLS_SHLIB=		yes
NO_FILTER_SHLIBS=	yes
LDCONFIG_DIRS=		%%PREFIX%%/lib/root %%PREFIX%%/lib/root/cint
MAN1=			cint.1 g2root.1 h2root.1 hadd.1 makecint.1 memprobe.1
MAN1+=			proofd.1 proofserv.1 rmkdepend.1 root-config.1 root.1
MAN1+=			root.exe.1 rootcint.1 rootd.1 rootn.exe.1

MODTESTS=		Event hsimple minexam tcollex tstring
MAKE_TENV=		${MAKE_ENV} CXX="${CXX}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

# The thread sub-system was not working for ROOT versions 3.x on FreeBSD 4.x
# systems. Meanwhile maybe it's working with some patches - but I have no
# FreeBSD 4.x system still running for testing  ;-)
.if ${OSVERSION} < 500016
CONFIGURE_ARGS+=	--disable-thread
PLIST_SUB+=		THREADS="@comment "
.else
CONFIGURE_ARGS+=	--enable-thread
CONFIGURE_ENV+=		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"	\
			PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKE_ENV+=		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"	\
			PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB+=		THREADS=""
.endif

post-patch:
	@${RM} ${WRKSRC}/test/Makefile.arch.orig
	@${REINPLACE_CMD} -e 's|auxcflags=\"-pthread|auxcflags=\"${PTHREAD_CFLAGS}| ;	\
		s|auxlibs=\"-pthread|auxlibs=\"${PTHREAD_LIBS}|'			\
			${WRKSRC}/config/root-config.in

.if defined(MAINTAINER_MODE)
test:	install
	(cd ${DOCSDIR}/test ;	\
	${SETENV} ${MAKE_TENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
. for module in ${MODTESTS}
	(cd ${DOCSDIR}/test ;	\
	${SETENV} LD_LIBRARY_PATH=.:${LD_LIBRARY_PATH} ./${module})
. endfor
.endif

.include <bsd.port.post.mk>
