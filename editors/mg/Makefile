# New ports collection makefile for:	mg
# Date created:			14 May 2001
# Whom:				Dima Dorfman <dima@unixfreak.org>
#
# $FreeBSD$
#

PORTNAME=	mg
PORTVERSION=	20010514
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.unixfreak.org/~dima/distfiles/
MASTER_SITE_SUBDIR=	dd

MAINTAINER=	dima@unixfreak.org

MAN1=		mg.1
MANCOMPRESSED=	maybe

# This isn't very scalable, but I'm lazy..
.if defined(NOMANCOMPRESS)
MANNAME=	mg.1
.else
MANNAME=	mg.1.gz
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mg ${PREFIX}/bin/mg
	@${INSTALL_MAN} ${WRKSRC}/${MANNAME} ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mg
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/tutorial \
		${PREFIX}/share/doc/mg
.endif

#
# Ports build/install stuff stops here.  Tarball creation stuff begins here.
#
.include <bsd.port.pre.mk>
CVS_CMD?=	cvs -z3
CVS_DATE=	Mon May 14 17:41:46 PDT 2001
CVS_SITES?=	anoncvs@anoncvs3.usa.openbsd.org:/cvs \
		anoncvs@anoncvs1.ca.openbsd.org:/cvs
CVS_MODULE=	src/usr.bin/mg

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
