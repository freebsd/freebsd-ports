PORTNAME=	sunpromake
CATEGORIES=	devel parallel

COMMENT=	Parallel-execution enabled SunOS make program, enhanced to fit POSIX
WWW=		http://schilytools.sourceforge.net/sunpromake.html

USE_LDCONFIG=	yes

CONFLICTS=	dmake

MASTERDIR=	${.CURDIR}/../../devel/schilybase
COMPONENTS=	sunpro

CXXFLAGS+=	-Wno-register

# these libraries are installed by the sunpro component
# but are internal to the program.  The author recommends
# not shipping them, so we don't.
post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libbsd.a
	${RM} ${STAGEDIR}${PREFIX}/lib/libmksh.a
	${RM} ${STAGEDIR}${PREFIX}/lib/libvroot.a

.include "${MASTERDIR}/Makefile.master"
