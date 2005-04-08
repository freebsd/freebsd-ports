# Ports collection Makefile for:	devel/bitkeeper
# Whom: 				Matthias Andree <matthias.andree@gmx.de>
# Date created:				2005-01-13
#
# $FreeBSD$
#

# NOTE: unfortunately, bitkeeper hardcodes it path, so moving files around
# does not work properly, not even for the documentation unfortunately.

# NOTE: we list no MASTER_SITES because the user must fetch the software
# manually after registering.

PORTNAME=	bitkeeper
PORTVERSION=	3.2.3
CATEGORIES=	devel
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scalable Distributed Software Configuration Management System

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
RESTRICTED=	"Redistribution is not permitted"
DEPRECATED=	"BitKeeper/Free will be discontinued on 2005-07-01"

USE_XLIB=	yes

MAN1=		bk-Basics-Overview.1 bk-Howto-bkd.1 bk-Howto-developer.1 \
		bk-Howto-setup.1 bk-Howto.1 bk-abort.1 bk-admin.1 \
		bk-annotate.1 bk-backups.1 bk-base64.1 bk-bin.1 bk-bk.1 \
		bk-bkcl.1 bk-bkd.1 bk-bkl.1 bk-bkscc.1 bk-c2r.1 bk-cat.1 \
		bk-changes.1 bk-check.1 bk-checksum.1 bk-chmod.1 bk-ci.1 \
		bk-citool.1 bk-clean.1 bk-clone.1 bk-cmdlog.1 bk-co.1 \
		bk-comments.1 bk-commit.1 bk-compatibility.1 bk-config-etc.1 \
		bk-config-gui.1 bk-config.1 bk-cp.1 bk-crypto.1 bk-cset.1 \
		bk-csetprune.1 bk-csets.1 bk-csettool.1 bk-delta.1 bk-diffs.1 \
		bk-difftool.1 bk-edit.1 bk-editor.1 bk-emacs.1 bk-export.1 \
		bk-extras.1 bk-files.1 bk-findkey.1 bk-fix.1 bk-flags.1 \
		bk-fmtool.1 bk-gca.1 bk-get.1 bk-gethost.1 bk-getuser.1 \
		bk-gnupatch.1 bk-gone.1 bk-grep.1 bk-help.1 bk-helptool.1 \
		bk-history.1 bk-id.1 bk-ignore.1 bk-import.1 bk-info.1 \
		bk-initscripts.1 bk-isascii.1 bk-key2rev.1 bk-keywords.1 \
		bk-lease.1 bk-level.1 bk-licensing.1 bk-links.1 bk-lock.1 \
		bk-lod.1 bk-log.1 bk-makepatch.1 bk-merge-binaries.1 \
		bk-merge.1 bk-merging.1 bk-more.1 bk-multiuser.1 bk-mv.1 \
		bk-mvdir.1 bk-names.1 bk-new.1 bk-newroot.1 bk-obscure.1 \
		bk-openlogging.1 bk-parent.1 bk-path.1 bk-pending.1 \
		bk-prompt.1 bk-prs.1 bk-pull.1 bk-push.1 bk-r2c.1 bk-range.1 \
		bk-rcs2sccs.1 bk-rcsparse.1 bk-receive.1 bk-relink.1 \
		bk-renames.1 bk-renametool.1 bk-renumber.1 bk-repogca.1 \
		bk-resolve.1 bk-revtool.1 bk-rm.1 bk-rmdel.1 bk-rmdir.1 \
		bk-rmgone.1 bk-root.1 bk-rset.1 bk-sane.1 bk-sccslog.1 \
		bk-send.1 bk-sendbug.1 bk-set.1 bk-setup.1 bk-setuptool.1 \
		bk-sfiles.1 bk-sfio.1 bk-smerge.1 bk-status.1 bk-stripdel.1 \
		bk-superset.1 bk-support.1 bk-tag.1 bk-takepatch.1 \
		bk-templates.1 bk-terms.1 bk-treediff.1 bk-triggers.1 \
		bk-undo.1 bk-undos.1 bk-unedit.1 bk-unlock.1 bk-unpull.1 \
		bk-unrm.1 bk-unwrap.1 bk-url.1 bk-users.1 bk-version.1 \
		bk-what.1 bk-wrap.1 bk-xflags.1 bk-zone.1
MANCOMPRESSED=	no

do-install:
	${MKDIR} ${WRKSRC}
	${INSTALL_PROGRAM} ${DISTDIR}/${DISTNAME} ${WRKSRC}/
	${MKDIR} ${PREFIX}/bitkeeper ${PREFIX}/bin
	${CHMOD} u+rx ${WRKSRC}/${DISTNAME}
	BK_NOLINKS=1 ${WRKSRC}/${DISTNAME} ${PREFIX}/bitkeeper
.for i in admin bk delta get prs rmdel unget
	${LN} -s ${PREFIX}/bitkeeper/$i ${PREFIX}/bin
.endfor
	for i in ${PREFIX}/bitkeeper/man/man1/bk-* ; do \
		${LN} $$i ${PREFIX}/man/man1/ ; \
	done
	${RM} -rf ${PREFIX}/bitkeeper/man

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501000 || ${OSVERSION} > 600000
DISTNAME=	bk-${PORTVERSION}-x86-freebsd4.1.bin
.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.endif
.else
DISTNAME=	bk-${PORTVERSION}-x86-freebsd5.1.bin
MD5_FILE=	${MASTERDIR}/distinfo-5
.endif

.if !exists(${DISTDIR}/${DISTNAME})
ECHO_MSG=	${PRINTF}
IGNORE=:\n\
Because of licensing restrictions, you must fetch the bitkeeper binary\n\
manually.  Please fill in one of the download forms at\n\
http://www.bitkeeper.com/Products.BK_Pro.Downloads.html and download\n\
the ${DISTFILES} file and place it in ${DISTDIR}.\n
.endif

.include <bsd.port.post.mk>
