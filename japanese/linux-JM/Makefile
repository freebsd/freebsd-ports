# New ports collection makefile for: linux-JM japanized man pages
# Date created:		21 Jan 2001
# Whom:			SADA Kenji <sada@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linux-JM
PORTVERSION=	${DATESPEC}
CATEGORIES=	japanese
MASTER_SITES=	http://www.linux.or.jp/JM/per-pkg/
DISTFILES=	${DISTFILES_GNU} ${DISTFILES_OTHERS}

MAINTAINER=	sada@FreeBSD.org

DIST_SUBDIR=	${PORTNAME}
MANSECS=	1 3 4 5 8
NO_MTREE=	yes
NO_WRKSUBDIR=	yes
PLIST=		${WRKDIR}/PLIST
SCRIPTS_ENV+=	MANSECS="${MANSECS}"
USE_PERL5=	yes

DATESPEC=	20010415
MANPAGES_GNU=	bash gdbm
MANPAGES_OTHERS= \
	bzip2 \
	cdparanoia cdrecord cvsup \
	dhcpcd \
	eject expect \
	fetchmail fort77 \
	mpg123 \
	ncftp netatalk \
	rdate \
	smbfs sudo \
	uudeview \
	wu-ftpd

.include <bsd.port.pre.mk>

DISTFILES_GNU!=\
	${ECHO_CMD} ${MANPAGES_GNU} \
	| ${SED} 's/[^ ]*/man-pages-ja-GNU_&-${DATESPEC}.tar.gz/g'
DISTFILES_OTHERS!=\
	${ECHO_CMD} ${MANPAGES_OTHERS} \
	| ${SED} 's/[^ ]*/man-pages-ja-&-${DATESPEC}.tar.gz/g'

post-extract:
.for i in Makefile Makefile.inc
	@${CP} ${FILESDIR}/$i ${WRKSRC}
.endfor
.for i in ${MANSECS}
	@cd ${WRKSRC} \
	 && ${MKDIR} man$i \
	 && ${LN} man-*/man$i/*.$i man$i
.endfor

post-build:
	@${ECHO_CMD} -n "" > ${PLIST}
	@for sec in ${MANSECS}; do \
	if [ -d ${WRKSRC}/man$${sec} ]; then \
		cd ${WRKSRC}/man$${sec}; \
		list=`${MAKE} pages-list`; \
		set `${ECHO_CMD} $$list " "|${SED} 's/\.\([0-9]\) /.\1 \1 /g'`; \
		while : ; do \
			case $$# in \
				0) break;; \
				[1]) ${ECHO_CMD} "can not happen" >/dev/tty; \
					exit 1;; \
			esac; \
			${ECHO_CMD} man/ja/man$$2/$$1.gz; shift 2; \
		done; \
	fi; \
	done|sort|uniq >>${PLIST}
.for sec in ${MANSECS}
	@${ECHO_CMD} '@unexec rmdir %D/man/ja/man'${sec}' 2>/dev/null || true' \
	 >>${PLIST}
.endfor
	@${ECHO_CMD} '@unexec rmdir %D/man/ja 2>/dev/null || true' >>${PLIST}

pre-install:
.for sec in ${MANSECS}
	@${MKDIR} ${PREFIX}/man/ja/man${sec}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
