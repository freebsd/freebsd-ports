# Created by: John Marino <draco@marino.st>
# $FreeBSD$

PORTNAME=	gps
PORTVERSION=	5.2.1
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	gps-5.2.1-1-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	draco@marino.st
COMMENT=	GNAT Programming Studio - IDE for Ada and many other languages

BUILD_DEPENDS=	gtkada>=2.24:${PORTSDIR}/x11-toolkits/gtkada \
		xmlada>=3.2:${PORTSDIR}/textproc/xmlada \
		gprbuild>=20120510:${PORTSDIR}/devel/gprbuild \
		sphinx-build:${PORTSDIR}/textproc/py-sphinx
LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp

LATEST_LINK=		gps-ide

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BZIP2=		yes
USE_PERL5_BUILD=	yes
ALL_TARGET=		default
USES=			ada
WRKSRC=			${WRKDIR}/gps-release-ide-${PORTVERSION}-src

CONFIGURE_ENV+=		AWK=/usr/bin/awk
DESTINY=		${WRKDIR}/destino
MAKE_ENV+=		DESTDIR=${DESTINY}

OPTIONS_DEFINE=		SYSLOG SQLITE PGSQL PYTHON READLINE
OPTIONS_DEFAULT=	SYSLOG SQLITE PYTHON READLINE

PYTHON_DESC=		Enable Python console

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:L}${OSREL}
.endif

CONFIGURE_ARGS+=	--disable-shared --with-gmp=${PREFIX}

################
##  READLINE  ##
################

.if ${PORT_OPTIONS:MREADLINE}
USES+=			readline
CONFIGURE_ARGS+=	--enable-gpl
.else
CONFIGURE_ARGS+=	--disable-readline
.endif

##############
##  SYSLOG  ##
##############

.if !${PORT_OPTIONS:MSYSLOG}
CONFIGURE_ARGS+=	--disable-syslog
.endif

##############
##  SQLITE  ##
##############

.if ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=	--with-sqlite=embedded
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

##################
##  POSTGRESQL  ##
##################

.if ${PORT_OPTIONS:MPGSQL}
CONFIGURE_ARGS+=	--with-postgresql=${PREFIX}
USE_PGSQL=		true
.endif

#####################
##  PYTHON / PYGTK ##
#####################

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--with-python=${PREFIX}
USE_PYTHON=		-2.7
USE_GNOME=		pygtk2
PYCOMPILE=		${PREFIX}/lib/${PYTHON_VERSION}/compileall.py
.else
CONFIGURE_ARGS+=	--without-python \
			--disable-pygtk \
			--disable-pygobject
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|@PREFIX@|${PREFIX}|g" \
	    ${WRKSRC}/gnatlib/src/gnatcoll_readline.gpr.in

pre-install:
.if ${PORT_OPTIONS:MPYTHON}
	${PYTHON_CMD} ${PYCOMPILE} ${WRKSRC}/share/plug-ins
	${PYTHON_CMD} ${PYCOMPILE} ${WRKSRC}/share/library
.endif

post-install:
	${RM} -rf ${DESTINY}${PREFIX}/share/doc/gps/html/users_guide/_sources
	${RM} -rf ${DESTINY}${PREFIX}/share/doc/gps/html/tutorial/_sources
	cd ${DESTINY}${PREFIX}; ${FIND} * -type d -empty -print | xargs rmdir
	${CP} -pR ${DESTINY}${PREFIX}/ ${PREFIX}/
	@cd ${DESTINY}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} > ${WRKDIR}/PLIST.all
	@cd ${DESTINY}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | ${SORT} -r | \
	   ${SED} -e '/share\/doc$$/d' -e '/share\/gps$$/d' \
	   -e '/share\/gps\/plug-ins$$/d' -e '/share\/examples$$/d' \
	   -e 's/^/@dirrm /g' >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/gps/plug-ins 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/gps 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/examples 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/doc 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@${CAT} ${WRKDIR}/PLIST.all >> ${TMPPLIST}

.include <bsd.port.mk>
