# Ports collection makefile for:  zhcon
# Date created:                   Sun Sep 9, 2001
# Whom:                           statue@freebsd.sinica.edu.tw
#
# $FreeBSD$
#

PORTNAME=	zhcon
PORTVERSION=	0.14f
PORTREVISION=	4
CATEGORIES=	chinese
MASTER_SITES=	http://freebsd.sinica.edu.tw/~statue/ \
		ftp://ftp.gnuchina.org/pub/linux/chinese/inputmethod/console/zhcon/BSDPort/ \
		http://www.cis.nctu.edu.tw/~gis89501/zhcon/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} zhb5-ime-2.tgz

MAINTAINER=	statue@freebsd.sinica.edu.tw

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		zhcon.1

.include <bsd.port.pre.mk>

.if defined(WITH_BIG5)
PLIST_SUB+=		BIG5IME=""
.else
PLIST_SUB+=		BIG5IME="@comment "
.endif

.if !defined(WITH_BIG5)
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Big5 IME support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_BIG5=yes\""
	@${ECHO_MSG}
.endif

post-patch:
.if ${OSVERSION} > 500012
	@${PERL} -pi -e 's,machine/console.h>,sys/consio.h>\n#include <sys/fbio.h>\n#include <sys/kbio.h>\n,' ${WRKSRC}/${PORTNAME}/*.cpp
.endif
.if defined(WITH_BIG5)
.for file in zhcon-0.14-big5-bar.diff.gz zhcon-0.14-big5-dirty-ime.diff.gz
	@${GZCAT} ${WRKDIR}/zh-big5-ime/${file} | ${PATCH} ${PATCH_DIST_ARGS:S/p0/p1/}
.endfor
.endif

post-build:
.if defined(WITH_BIG5)
	@cd ${WRKDIR}/zh-big5-ime; ${SETENV} BATCH=yes ./configure; make all
.endif

post-install:
.if defined(WITH_BIG5)
.for file in big5-*.mb
	@${INSTALL_DATA} ${WRKDIR}/zh-big5-ime/mb/${file} ${PREFIX}/lib/zhcon
.endfor
	@${INSTALL_DATA} ${WRKDIR}/zh-big5-ime/zhcon.cfg.big5 ${PREFIX}/lib/zhcon/zhcon.cfg
.endif

.include <bsd.port.post.mk>
