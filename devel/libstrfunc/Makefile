# New ports collection makefile for:	libstrfunc
# Date created:				2001-07-19
# Whom:					Lev Walkin <vlm@spelio.net.ru>
#
# $FreeBSD$
#

PORTNAME=	libstrfunc
PORTVERSION=	7.3
CATEGORIES=	devel www
MASTER_SITES=	http://www.spelio.net.ru/soft/

MAINTAINER=	vlm@spelio.net.ru

INSTALL_TARGET=	install install-man
INSTALLS_SHLIB=	yes

MANCOMPRESSED=	no
MAN3=	strfunc.3 libstrfunc.3 sf_slist.3 sinit.3 slist.3 sadd.3 sadd2.3 \
	sadd_attach.3 sdel.3 sins.3 simport.3 sfree.3 sclear.3 sarray.3 \
	mkarray.3 charize.3 sfind.3 scfind.3 find.3 cfind.3 count_values.3 \
	copy_values.3 free_values.3 sget.3 scget.3 sgetp.3 scgetp.3 scopy.3 \
	sf_split.3 split.3 splitf.3 splitquotable.3 split_network.3 sjoin.3 \
	join.3 sf_cgi.3 param.3 param2.3 params.3 set_cookie.3 cookie.3 \
	cookies.3 html_quote.3 url_encode.3 url_decode.3 getlanguageprefs.3 \
	sf_mime.3 base64_encode.3 base64_decode.3 quoted_printable_decode.3 \
	mime_word_decode.3 sf_time.3 strtotime.3 timetostr.3 sf_cfg.3 \
	cfgread.3 cfgget.3 cfgget2.3 sf_fmt.3 format_init.3 format_free.3 \
	format_metarule.3 formatf.3 format_lastsize.3 format_lastresult.3 \
	format_detach.3 sf_sbuf.3 sbuf.3 sbuf_init.3 sbuf_free.3 \
	sbuf_detach.3 sbuf_clear.3 sbuf_zero.3 sbuf_extend.3 sbuf_add.3 \
	sbuf_add2.3 sbuf_sprintf.3 sbuf_fgets.3 sf_sed.3 sed.3 sed_compile.3 \
	sed_exec.3 sed_free.3 sf_file.3 initfdpos.3 initFILEpos.3 adjfdpos.3 \
	adjFILEpos.3 sf_misc.3 eq.3 ecq.3 countchar.3 countchar2.3 \
	countstr.3 replace.3 replace_detach.3 limittextwidth.3 sf_mem.3 \
	strndup.3 sf_strdup.3 sf_malloc.3 sf_calloc.3 sf_realloc.3 \
	strfunc_ctl.3

post-install:
	@strip ${PREFIX}/bin/timetostr
	@strip ${PREFIX}/bin/strtotime
	@strip ${PREFIX}/bin/posdump

.include <bsd.port.mk>
