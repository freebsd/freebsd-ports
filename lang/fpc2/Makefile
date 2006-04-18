# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			25 Jun 2005
# Whom: 				Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	fpc
PORTVERSION=	2.0.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.freepascal.org/pub/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		ftp://planetmirror.com/pub/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		ftp://ftp.jp.freepascal.org/mirror/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		ftp://freepascal.stack.nl/pub/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		ftp://ftp.no.freepascal.org/pub/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		ftp://ftp.us.freepascal.org/pub/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freepascal
DISTNAME=	${PORTNAME}-${PORTVERSION}.i386-freebsd
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Pascal compiler with Turbo, Delphi and other extensions

BUILDNAME=	i386-freebsd

# Define some libraries for fpc using OPTIONS
OPTIONS=	BFD "Install bfd support" off \
		FCL "Install fcl support" off \
		FORMS "Install forms support" off \
		FPGTK "Install fpgtk support" off \
		FV "Install fv support" off \
		GCONF "Install gconf support" off \
		GDBINT "Install gdbint support" off \
		GDBM "Install GDBM support" off \
		GGI "Install ggi support" off \
		GNOME "Install gnome support" off \
		GTK "Install gtk support" off \
		GTK2 "Install gtk2 support" off \
		IBASE "Install interbase support" off \
		IMLIB "Install imlib support" off \
		ASYNC "Install libacync support" off \
		GD "Install libgd support" off \
		PNG "Install libpng support" off \
		MD5 "Install md5 support" off \
		MYSQL "Install mysql support" off \
		NCURSES "Install ncurses support" off \
		NETDB "Install netdb support" off \
		ODBC "Install odbc support" off \
		OPENGL "Install opengl support" off \
		ORACLE "Install oracle support" off \
		PASJPEG "Install pascal libjpeg support" off \
		PASZLIB "Install pascal zlib support" off \
		POSTGRES "Install postgresql support" off \
		PTHREADS "Install pthreads support" off \
		REGEXP "Install regexp support" off \
		SQLITE "Install sqlite support" off \
		SVGALIB "Install svgalib support" off \
		SYSLOG "Install syslog support" off \
		TCL "Install tcl support" off \
		UTMP "Install utmp support" off \
		UNZIP "Install unzip support" off \
		X11 "Install x11 support" off \
		ZLIB "Install zlib support" off \
		ZVT "Install zvt support" off

.include <bsd.port.pre.mk>

USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
PKGDEINSTALL=	${PKGINSTALL}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAN1=	bin2obj.1 \
	data2inc.1 \
	delp.1 \
	fd2pascal.1 \
	fpc.1 \
	fpcmake.1 \
	fpdoc.1 \
	fprcp.1 \
	h2pas.1 \
	h2paspp.1 \
	makeskel.1 \
	plex.1 \
	postw32.1 \
	ppc386.1 \
	ppcarm.1 \
	ppcppc.1 \
	ppcsparc.1 \
	ppcx64.1 \
	ppdep.1 \
	ppudump.1 \
	ppufiles.1 \
	ppumove.1 \
	ptop.1 \
	pyacc.1 \
	rstconv.1 \
	unitdiff.1
MAN5=	fpc.cfg.5 fpcmake.5 ptop.cfg.5

# only need misc/compat4x if using the pre-built ppc386
.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.endif

# Build units list
.if defined(WITH_BFD)
UNITS+=	bfd
.endif
.if defined(WITH_FCL)
UNITS+=	fcl
PLIST_SUB+=	FCL=""
.else
PLIST_SUB+=	FCL="@comment "
.endif
.if defined(WITH_FORMS)
UNITS+=	forms
PLIST_SUB+=	FORMS=""
.else
PLIST_SUB+=	FORMS="@comment "
.endif
.if defined(WITH_FPGTK)
UNITS+=	fpgtk
.endif
.if defined(WITH_FV)
UNITS+=	fv
.endif
.if defined(WITH_GCONF)
UNITS+=	gconf
.endif
.if defined(WITH_GDBINT)
UNITS+=	gdbint
.endif
.if defined(WITH_GDBM)
UNITS+=	gdbm
.endif
.if defined(WITH_GGI)
UNITS+=	ggi
.endif
.if defined(WITH_GNOME)
UNITS+=	gnome
.endif
.if defined(WITH_GTK)
UNITS+=	gtk
.endif
.if defined(WITH_GTK2)
UNITS+=	gtk2
.endif
.if defined(WITH_IBASE)
UNITS+=	ibase
.endif
.if defined(WITH_IMLIB)
UNITS+=	imlib
.endif
.if defined(WITH_ASYNC)
UNITS+=	libasync
.endif
.if defined(WITH_GD)
UNITS+=	libgd
.endif
.if defined(WITH_PNG)
UNITS+=	libpng
.endif
.if defined(WITH_MD5)
UNITS+=	md5
.endif
.if defined(WITH_MYSQL)
UNITS+=	mysql
.endif
.if defined(WITH_NCURSES)
UNITS+=	ncurses
.endif
.if defined(WITH_NETDB)
UNITS+=	netdb
.endif
.if defined(WITH_ODBC)
UNITS+=	odbc
.endif
.if defined(WITH_OPENGL)
UNITS+=	opengl
.endif
.if defined(WITH_ORACLE)
UNITS+=	oracle
.endif
.if defined(WITH_PASJPEG)
UNITS+=	pasjpeg
.endif
.if defined(WITH_PASZLIB)
UNITS+=	paszlib
.endif
.if defined(WITH_POSTGRES)
UNITS+=	postgres
.endif
.if defined(WITH_PTHREADS)
UNITS+=	pthreads
.endif
.if defined(WITH_REGEXP)
UNITS+=	regexpr
.endif
.if defined(WITH_SQLITE)
UNITS+=	sqlite
.endif
.if defined(WITH_SVGALIB)
UNITS+=	svgalib
.endif
.if defined(WITH_SYSLOG)
UNITS+=	syslog
.endif
.if defined(WITH_TCL)
UNITS+=	tcl
.endif
.if defined(WITH_UNZIP)
UNITS+=	unzip
.endif
.if defined(WITH_UTMP)
UNITS+=	utmp
.endif
.if defined(WITH_X11)
UNITS+=	x11
.endif
.if defined(WITH_ZLIB)
UNITS+=	zlib
.endif
.if defined(WITH_ZVT)
UNITS+=	zvt
.endif

do-extract:
# unpack distribution
	@${MKDIR} ${WRKSRC}
	@${TAR} xf ${DISTDIR}/${DISTNAME}.tar --directory ${WRKSRC}
# unpack pre-compiled binaries distribution
	@${MKDIR} ${WRKSRC}/binary
	@${TAR} xf ${WRKSRC}/binary.${BUILDNAME}.tar --directory ${WRKSRC}/binary
# create a local binary ppc386
	@${MKDIR} ${WRKSRC}/boot
	@${TAR} zxf ${WRKSRC}/binary/base.${BUILDNAME}.tar.gz \
		--directory ${WRKSRC}/boot
	@${TAR} zxf ${WRKSRC}/binary/utils.${BUILDNAME}.tar.gz \
		--directory ${WRKSRC}/boot
# Install optional packages
.if defined(UNITS)
.  for unit in ${UNITS}
	@${TAR} zxf ${WRKSRC}/binary/units-${unit}.${BUILDNAME}.tar.gz \
		--directory ${WRKSRC}/boot
	@${LS} ${WRKSRC}/boot/lib/fpc/${PORTVERSION}/units/${BUILDNAME}/${unit} | \
		${SED} -e 's,^,lib/fpc/${PORTVERSION}/units/${BUILDNAME}/${unit}/,' \
		>> ${TMPPLIST}.modules
	@${ECHO} "@dirrm lib/fpc/${PORTVERSION}/units/${BUILDNAME}/${unit}" >> ${TMPPLIST}.modules
.  endfor
.endif

do-install:
	# Installing binaries
	${INSTALL_SCRIPT} ${WRKSRC}/boot/bin/* ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/boot/share/doc/fpc-${PORTVERSION}/fpc/* ${DOCSDIR}
.endif
	# Installing fpc libs
	${CP} -r ${WRKSRC}/boot/lib/* ${PREFIX}/lib
	# Installing manpages
	${INSTALL_DATA} ${WRKSRC}/boot/man/man1/* ${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/boot/man/man5/* ${MAN1PREFIX}/man/man5

post-install:
.if defined(UNITS)
	@${CAT} ${TMPPLIST}.modules ${TMPPLIST} > ${TMPPLIST}.result
	@${MV} ${TMPPLIST}.result ${TMPPLIST}
.endif
	@${LN} -s ${PREFIX}/lib/fpc/${PORTVERSION}/ppc386 ${PREFIX}/bin
	${SH} ${PREFIX}/lib/fpc/${PORTVERSION}/samplecfg ${PREFIX}/lib/fpc/${PORTVERSION} ${PREFIX}/etc

.include <bsd.port.post.mk>
