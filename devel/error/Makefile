# New ports collection makefile for:	error
# Date created:			16 June 2001
# Whom:				dd
#
# $FreeBSD$
#

PORTNAME=	error
PORTVERSION=	20010616
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.unixfreak.org/~dima/distfiles/
MASTER_SITE_SUBDIR=	dd

MAINTAINER=	dd@FreeBSD.org
COMMENT=	Analyze diagnostic error output from compilers and other processors

MANSECTS=	1
MAN1=		error.1
MANCOMPRESSED=	maybe
PLIST_FILES=	bin/error

# MAN page COMPression SUFFIX
.if !defined(NOMANCOMPRESS)
MANCOMPSUFFIX=	.gz
.else
MANCOMPSUFFIX=
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/error ${PREFIX}/bin/error
.for __s in ${MANSECTS}
.for __m in ${MAN${__s}:S/$/${MANCOMPSUFFIX}/}
	@${INSTALL_MAN} ${WRKSRC}/${__m} ${PREFIX}/man/man${__s}/${__m}
.endfor
.endfor

#
# Ports build/install stuff stops here.  Tarball creation stuff begins here.
#
.include <bsd.port.pre.mk>
CVS_CMD?=	cvs -z3
CVS_DATE=	Sun Jun  16 15:58:14 PDT 2001
CVS_SITES?=	anoncvs@anoncvs.openbsd.org:/cvs
CVS_MODULE=	src/usr.bin/error

#
# CVS checkout stuff mostly stolen from security/openssh-askpass port by
# kris@freebsd.org
#
tarball:
	@${MKDIR} ${DISTDIR}/${PKGNAME} && \
	cd ${DISTDIR}/${PKGNAME}; \
	for CVS_SITE in ${CVS_SITES}; do \
		${ECHO_MSG} ">> Attempting to check out from $${CVS_SITE}."; \
		if ${CVS_CMD} -d $${CVS_SITE} co -D "${CVS_DATE}" \
		    ${CVS_MODULE}; then \
			cd ${DISTDIR}; \
			${ECHO_MSG} ">> Creating dist tarball in ${DISTDIR}"; \
			${ECHO_MSG} ">> \"${PKGNAME}.tar.gz\"."; \
			${MV} ${PKGNAME}/${CVS_MODULE} \
				${PKGNAME}/${CVS_MODULE:H}/${PKGNAME}; \
			${TAR} -cz \
				-X ${FILESDIR}/tarignore \
				-f ${PKGNAME}.tar.gz \
				-C ${PKGNAME}/${CVS_MODULE:H} \
				${PKGNAME}; \
			exit; \
		fi \
	done; \
	${RMDIR} ${DISTDIR}/${PKGNAME}; \
	${ECHO_MSG} ">> CVS checkout failed."; \
	exit 1;

.include <bsd.port.post.mk>
