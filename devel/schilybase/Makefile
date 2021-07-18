PORTNAME=	schilybase
CATEGORIES=	devel

COMMENT=	Support files and libraries for the schilytools

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	PROFILE DOCS
OPTIONS_DEFAULT=DOCS
OPTIONS_SUB=	yes

# do not reorder: order required for build to succeed
BOOTSTRAP_SMAKE?=	yes
COMPONENTS=	conf \
		inc \
		include \
		include/schily \
		libschily \
		libdeflt \
		libscg \
		libscg/scg \
		libxtermcap \
		libcdrdeflt \
		libdbgmalloc \
		libedc \
		libfile \
		libfind \
		libgetopt \
		libhfs_iso \
		libmdigest \
		libparanoia \
		librmt \
		librscg \
		libscgcmd \
		libshedit \
		libsiconv \
		libsiconv/tables \
		libstreamar \
		man \
		man/man4

post-install-PROFILE-off:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/profiled

.include "Makefile.master"
