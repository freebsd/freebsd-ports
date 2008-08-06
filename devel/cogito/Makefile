# Ports collection makefile for: cogito
# Date created:		31 May 2005
# Whom:			Michael Seyfert <michaels@sdf.lonestar.org>
#
# $FreeBSD$
#

PORTNAME=	cogito
PORTVERSION=	0.17.2
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.kernel.org/pub/software/scm/cogito/ \
		http://www.uk.kernel.org/pub/software/scm/cogito/ \
		http://www.us.kernel.org/pub/software/scm/cogito/ \
		http://www.jp.kernel.org/pub/software/scm/cogito/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Cogito Version Control System

BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		xmlto:${PORTSDIR}/textproc/xmlto
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	git:${PORTSDIR}/devel/git \
		bash:${PORTSDIR}/shells/bash \
		rsync:${PORTSDIR}/net/rsync

USE_BZIP2=	yes
USE_GMAKE=	yes
.if !defined(NOPORTDOCS)
ALL_TARGET=	all doc
INSTALL_TARGET=	install install-doc
.endif

# We set HOME to PREFIX. This will install the files in the proper location.
MAKE_ENV+=	HOME=${PREFIX} CPATH=${PREFIX}/include LIBRARY_PATH=${PREFIX}/lib
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

CONTRIB_FILES=	${WRKDIR}/${DISTNAME}/contrib/gitfeedmaillist.sh \
		${WRKDIR}/${DISTNAME}/contrib/ciabot.pl

MAN1 =		cg-add.1 \
		cg-admin-cat.1 \
		cg-admin-ls.1 \
		cg-admin-lsobj.1 \
		cg-admin-rewritehist.1 \
		cg-admin-setuprepo.1 \
		cg-admin-uncommit.1 \
		cg-branch-add.1 \
		cg-branch-chg.1 \
		cg-branch-ls.1 \
		cg-clean.1 \
		cg-clone.1 \
		cg-commit.1 \
		cg-diff.1 \
		cg-export.1 \
		cg-fetch.1 \
		cg-help.1 \
		cg-init.1 \
		cg-log.1 \
		cg-merge.1 \
		cg-mkpatch.1 \
		cg-mv.1 \
		cg-object-id.1 \
		cg-patch.1 \
		cg-push.1 \
		cg-reset.1 \
		cg-restore.1 \
		cg-rm.1 \
		cg-seek.1 \
		cg-status.1 \
		cg-switch.1 \
		cg-tag-ls.1 \
		cg-tag.1 \
		cg-update.1 \
		cg-version.1 \
		cg.1
MAN7=		cogito.7 \
		cg-ref.7

post-install:
	${INSTALL_SCRIPT} ${CONTRIB_FILES} ${PREFIX}/bin

.include <bsd.port.mk>
