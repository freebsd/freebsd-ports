# New ports collection makefile for:    KeLP
# Date created:         5 May 2000
# Whom:                 Michael Wu <keichii@iteration.net>
# $FreeBSD$
#

PORTNAME=	kelp
PORTVERSION=	1.3_1
CATEGORIES=	devel parallel
MASTER_SITES=	ftp://ftp.cs.ucsd.edu/pub/scg/KeLP/
DISTNAME=	KeLP1.3

MAINTAINER=	keichii@freebsd.org

BUILD_DEPENDS=	${LOCALBASE}/mpich/bin/mpirun:${PORTSDIR}/net/mpich

MAN3=		kelp.3
MANCOMPRESSED=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}_src

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAKE_ENV=	KELP_HOME=${WRKSRC}

#FIND=		/usr/bin/find
INST_DIST=	bin dgrid doc dock examples include kelp lib mp++ tools
INST_KELP_HOME=	${LOCALBASE}/kelp

post-patch:
	@${PERL} -pi -e 's,API2,./API2, ; \
		s,API3,./API3,' ${WRKSRC}/examples/API/makefile
	@${PERL} -pi -e 's,%LOCALBASE%,${LOCALBASE},' ${WRKSRC}/configure

do-install:
	@${MKDIR} ${INST_KELP_HOME}
	@${ECHO} "Installing kelp into ${INST_KELP_HOME}"
.for i in ${INST_DIST}
	@${CP} -r ${WRKSRC}/${i} ${INST_KELP_HOME}
.endfor
	@${ECHO} "Deleting un-needed files."
	@cd ${INST_KELP_HOME} ; \
	find ./ \
	\( \
	-name "*.orig" -or -name "*.old" -or -name "*.log" -or -name "*.out" \
	-or -name "*.o" -or -name "*.bck" -or -name "*.o2k" -or -name "*.ls" \
	\) -delete

	@cd ${INST_KELP_HOME} ; ${RM} lib/.empty_file_for_tar

	@${ECHO} "Changing mode of files that shouldn't be executable."
	@cd ${INST_KELP_HOME} ; \
	find ./ \
	\( \
	-name "*.C" -or -name "*.h" -or -name "*.m4" -or -name README \
	-or -name COPYING -or -name "*.c" -or -name "*.F" -or -name "*.f" \
	\) -exec ${CHMOD} +r-x {} \;

	@${ECHO} "Changing executable files mode to 555."
	@cd ${INST_KELP_HOME} ; \
	find ./ -type f \( -perm -+x -or -perm 750 \) \
	-exec ${CHMOD} 555 {} \;

	@${ECHO} "Changing normal files mode to 444."
	@cd ${INST_KELP_HOME} ; \
	find ./ -type f \( -perm 644 -or -perm 640 \) \
	-exec ${CHMOD} 444 {} \;

.if !defined(NOPORTDOCS)
	@${GZIP_CMD} ${WRKSRC}/man/man3/kelp.3 -c > \
	${LOCALBASE}/man/man3/kelp.3.gz
.endif
	@${CAT} ${PKGMESSAGE}
.include <bsd.port.mk>
