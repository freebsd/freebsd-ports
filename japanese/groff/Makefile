# New ports collection makefile for:	ja-groff
# Version required:	1.10+0.99
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

DISTNAME=	groff-1.10
PKGNAME=	ja-groff-0.99
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	groff

PATCH_SITES=	ftp://ftp.ae.keio.ac.jp/pub/GNU/ \
		ftp://ftp.tohoku.ac.jp/pub/GNU/japanese/
PATCHFILES=	jgroff-0.99.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	graphite@jp.freebsd.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

DESCS=		${WRKSRC}/devnippon/DESC.proto ${WRKSRC}/devps/DESC.in

#for not writing "/usr/local" explicitly in the patch
post-patch:
	@for f in ${DESCS}; do \
	  ${MV} -f $${f} $${f}.tmp; \
	  ${SED} -e '$$d' $${f}.tmp > $${f}; \
	  case $${f} in \
  	    */devnippon/*) \
		${ECHO} "postpro ${PREFIX}/bin/grotty" >> $${f}; \
		;; \
	    */devps/*) \
		${ECHO} "postpro ${PREFIX}/bin/grops" >> $${f}; \
		;; \
	  esac; \
	done

.include <bsd.port.pre.mk>

post-install:
	@${CP} -p /usr/share/tmac/tmac.an ${PREFIX}/share/groff/tmac
	@${CP} -p /usr/share/tmac/tmac.andoc ${PREFIX}/share/groff/tmac
	@${CP} -p /usr/share/tmac/tmac.groff_an ${PREFIX}/share/groff/tmac
	@${CP} -p /usr/share/tmac/tmac.orig_me ${PREFIX}/share/groff/tmac
	@${CP} -p /usr/share/tmac/tmac.vgrind ${PREFIX}/share/groff/tmac
	@${CP} -p /usr/share/tmac/eqnrc ${PREFIX}/share/groff/tmac
.if ${OSVERSION} >= 400000
	@${CP} -p /usr/share/tmac/locale/hyphen.us-ru ${PREFIX}/share/groff/tmac
.else
	@${CP} -p /usr/share/tmac/hyphen.us-ru ${PREFIX}/share/groff/tmac
.endif
	@${CP} -p /usr/share/tmac/troffrc ${PREFIX}/share/groff/tmac
	@${CP} -p /usr/share/tmac/mdoc/doc-common ${PREFIX}/share/groff/tmac/mdoc
	@${CP} -p /usr/share/tmac/mdoc/doc-syms ${PREFIX}/share/groff/tmac/mdoc
	@/usr/bin/patch -d ${PREFIX}/share/groff/tmac < ${FILESDIR}/rc.diff

.include <bsd.port.post.mk>
