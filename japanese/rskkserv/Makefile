# New ports collection makefile for:	rskkserv
# Date created:		18 Aug 2000
# Whom:                 Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rskkserv
PORTVERSION=	2.95.4
PORTREVISION=	0
CATEGORIES=	japanese ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	rskkserv/15241
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	An alternative implementation of skkserv written in Ruby

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/tcpwrap.so:${PORTSDIR}/security/ruby-tcpwrap \
		${SKKJISYO_BASE}/${SKKJISYO}:${SKK_MASTERDIR}

.if defined(WITH_RUBY_CDB)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/cdb.so:${PORTSDIR}/databases/ruby-cdb
.endif

.if defined(WITH_RUBY_EB)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/eb.so:${PORTSDIR}/japanese/ruby-eb
.endif

USE_RUBY=	yes
USE_AUTOTOOLS=	autoconf213
USE_GMAKE=	yes
USE_RC_SUBR=	rskkserv

CONFIGURE_ARGS=	--with-ruby="${RUBY}" \
		--with-dicfile="${SKKJISYO_BASE}/${SKKJISYO}" \
		--with-cachedir="${SKKJISYO_BASE}" \
		--with-logdir="/var/log" \
		--with-piddir="/var/run"
MAKE_ARGS=	SKKSERV=rskkserv

SKKJISYO_SIZE?=	L
SKKJISYO_BASE=	${LOCALBASE}/share/skk
SKKJISYO=	SKK-JISYO.${SKKJISYO_SIZE}
SKK_MASTERDIR=	${PORTSDIR}/japanese/skk-jisyo

MAN1=		rskkserv.1
MANLANG=	"" ja

DOCS_EN=	ChangeLog
DOCS_JA=	TODO

post-extract:
	${LN} -s ${WRKSRC}/skkserv.rb.in ${WRKSRC}/rskkserv.in

post-patch:
	${RUBY} -i -ne 'if $$. == 1 then puts "#!@RUBY@" else puts $$_ end' ${WRKSRC}/skkserv.rb.in
	${RUBY} -i -p \
		-e 'gsub %r:/usr/share/skk:, %q:${SKKJISYO_BASE}:' \
		-e 'gsub %r:/opt/epwing/(\w+):, %q:${LOCALBASE}/share/dict/\\1-fpw:' \
		-e 'gsub %r:SKK-JISYO\\.L:, %q:${SKKJISYO}:' \
		-e 'sub %r%(CACHEDIR\s*=\s*")[^"]*(")%, \
					     %q%\\1${SKKJISYO_BASE}\\2%' \
		${WRKSRC}/doc/rskkserv.conf.sample
	${RUBY} -i -p \
		-e 'sub %r%/usr/bin/ruby%, %q%${RUBY}% ' \
		${WRKSRC}/doc/conf-o2n.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif
	${INSTALL_MAN} ${WRKSRC}/doc/rskkserv.1 ${MANPREFIX}/man/man1/rskkserv.1
	${INSTALL_MAN} ${WRKSRC}/doc/rskkserv.1.ja_JP.eucJP ${MANPREFIX}/man/ja/man1/rskkserv.1
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/conf-o2n.rb ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/rskkserv.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/rskkserv.conf.sample ${EXAMPLESDIR}

.include <bsd.port.mk>
