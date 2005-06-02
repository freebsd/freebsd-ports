# New ports collection makefile for:    FreeWnn for Japanese
# Date created:     20 July 1997
# Whom:         Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	FreeWnn
PORTVERSION=	${WMMVERSION:S/-/./}
#PORTREVISION=	1
CATEGORIES?=	japanese
MASTER_SITES=	ftp://ftp.freewnn.org/pub/FreeWnn/alpha/
PKGNAMESUFFIX?=	-lib
DISTNAME=	${PORTNAME}-${WMMVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	A Japanese/Chinese/Korean input method (Japanese client libraries)

WRKSRC=	${WRKDIR}/FreeWnn-1.10-pl020
ALL_TARGET=	includes all
INSTALL_TARGET=	install install.man
GNU_CONFIGURE=	yes
USE_AUTOCONF_VER=	213
USE_LIBTOOL_VER=15
MAKE_ARGS=	CDEBUGFLAGS="${CFLAGS}"
INSTALLS_SHLIB=	yes
USE_BZIP2=	yes

WMMVERSION=	1.1.1-a020

WNN?=		Wnn
.if (${PKGNAMESUFFIX} == -lib)
CONFIGURE_ARGS=	--enable-server=no
## I must use MLINKS, but ....
NOMANCOMPRESS=	yes
.else
CONFIGURE_ARGS=	--enable-libraries=no
.endif

.if (${WNN} == Wnn)
CONFIGURE_ARGS+= --enable-cWnn=no --enable-kWnn=no
MANLANG=	ja
CONFIGURE_ARGS+= --mandir=${PREFIX}/man/ja
.if (${PKGNAMESUFFIX} == -lib)
MAN3=	jl_bun_suu.3 jl_c_zenkouho.3 jl_close.3 jl_connect.3 jl_connect_lang.3 \
	jl_dai_top.3 jl_dic_add.3 jl_dic_add_e.3 jl_dic_comment_set.3 \
	jl_dic_comment_set_e.3 jl_dic_delete.3 jl_dic_delete_e.3 jl_dic_list.3 \
	jl_dic_list_e.3 jl_dic_save.3 jl_dic_save_all.3 jl_dic_save_all_e.3 \
	jl_dic_save_e.3 jl_dic_use.3 jl_dic_use_e.3 jl_disconnect.3 jl_env.3 \
	jl_env_get.3 jl_env_set.3 jl_env_sticky.3 jl_env_sticky_e.3 \
	jl_env_un_sticky.3 jl_env_un_sticky_e.3 jl_fuzokugo_get.3 \
	jl_fuzokugo_get_e.3 jl_fuzokugo_set.3 jl_fuzokugo_set_e.3 jl_get_kanji.3 \
	jl_get_yomi.3 jl_get_zenkouho_kanji.3 jl_hinsi_dicts.3 jl_hinsi_dicts_e.3 \
	jl_hinsi_list.3 jl_hinsi_list_e.3 jl_hinsi_name.3 jl_hinsi_name_e.3 \
	jl_hinsi_number.3 jl_hinsi_number_e.3 jl_inspect.3 jl_isconnect.3 \
	jl_isconnect_e.3 jl_jiri_len.3 jl_kanji_len.3 jl_kill.3 jl_next.3 \
	jl_next_dai.3 jl_nobi_conv.3 jl_open.3 jl_open_lang.3 jl_param_get.3 \
	jl_param_get_e.3 jl_param_set.3 jl_param_set_e.3 jl_previous.3 \
	jl_previous_dai.3 jl_ren_conv.3 jl_set_env_wnnrc.3 jl_set_jikouho.3 \
	jl_set_jikouho_dai.3 jl_tan_conv.3 jl_update_hindo.3 jl_word_add.3 \
	jl_word_add_e.3 jl_word_comment_set.3 jl_word_comment_set_e.3 \
	jl_word_delete.3 jl_word_delete_e.3 jl_word_info.3 jl_word_info_e.3 \
	jl_word_search.3 jl_word_search_by_env.3 jl_word_search_by_env_e.3 \
	jl_word_search_e.3 jl_word_use.3 jl_word_use_e.3 jl_yomi_len.3 \
	jl_zenkouho.3 jl_zenkouho_bun.3 jl_zenkouho_dai.3 jl_zenkouho_daip.3 \
	jl_zenkouho_suu.3 js_access.3 js_close.3 js_connect.3 js_dic_add.3 \
	js_dic_delete.3 js_dic_file_create.3 js_dic_file_create_client.3 \
	js_dic_info.3 js_dic_list.3 js_dic_list_all.3 js_dic_use.3 js_disconnect.3 \
	js_env_exist.3 js_env_list.3 js_env_sticky.3 js_env_un_sticky.3 \
	js_file_comment_set.3 js_file_discard.3 js_file_info.3 js_file_list.3 \
	js_file_list_all.3 js_file_loaded.3 js_file_loaded_local.3 \
	js_file_password_set.3 js_file_read.3 js_file_receive.3 js_file_remove.3 \
	js_file_remove_client.3 js_file_send.3 js_file_stat.3 js_file_write.3 \
	js_fuzokugo_get.3 js_fuzokugo_set.3 js_get_lang.3 js_hindo_file_create.3 \
	js_hindo_file_create_client.3 js_hindo_set.3 js_hinsi_dicts.3 \
	js_hinsi_list.3 js_hinsi_name.3 js_hinsi_number.3 js_hinsi_table_set.3 \
	js_isconnect.3 js_kanren.3 js_kantan_dai.3 js_kantan_sho.3 \
	js_kanzen_dai.3 js_kanzen_sho.3 js_kill.3 js_mkdir.3 js_open.3 \
	js_open_lang.3 js_param_get.3 js_param_set.3 js_set_lang.3 \
	js_version.3 js_who.3 js_word_add.3 js_word_comment_set.3 \
	js_word_delete.3 js_word_info.3 js_word_search.3 js_word_search_by_env.3 \
	msg_close.3 msg_get.3 msg_open.3 romkan_clear.3 romkan_dispmode.3 \
	romkan_getc.3 romkan_init.3 romkan_next.3 romkan_ungetc.3
.else
#BUILD_DEPENDS=	${LOCALBASE}/lib/libwnn.a:${PORTSDIR}/japanese/FreeWnn-lib
#RUN_DEPENDS=	${LOCALBASE}/lib/wnn/ja_JP/jserverrc:${PORTSDIR}/japanese/FreeWnn-lib
LIB_DEPENDS=	wnn.0:${PORTSDIR}/japanese/FreeWnn-lib
CONFIGURE_ARGS+= --with-libwnn=-lwnn --with-wnn-libraries="${PREFIX}/lib"
MAN1=	atod.1 atof.1 dtoa.1 jserver.1 oldatonewa.1 uum.1 wddel.1 wdreg.1 \
	wnnkill.1 wnnstat.1 wnntouch.1
MAN4=	2a_ctrl.4 2b_romkana.4 cvt_key_tbl.4 fzk.data.4 fzk.u.4 hinsi_data.4 \
	jserverrc.4 mode.4 serverdefs.4 ujis_dic.4 uumkey.4 uumrc.4 wnnenvrc.4
MAN5=	pubdic.5 usr_dic.5
.endif
.elif (${WNN} == cWnn)
CONFIGURE_ARGS+=	--enable-Wnn=no --enable-kWnn=no
.if (${PKGNAMESUFFIX} == -server)
#BUILD_DEPENDS=	${LOCALBASE}/lib/libcwnn.a:${PORTSDIR}/chinese/FreeWnn-lib
#RUN_DEPENDS=	${LOCALBASE}/lib/wnn/zh_CN/cserverrc:${PORTSDIR}/chinese/FreeWnn-lib
LIB_DEPENDS=	cwnn.0:${PORTSDIR}/chinese/FreeWnn-lib
MAN1=	cserver.1 cuum.1 cwnnkill.1 cwnnstat.1 catod.1 catof.1 cdicsort.1 \
	cdtoa.1 cwddel.1 cwdreg.1 cwnntouch.1
MAN4=	cst_end.4 cwnn.4 cenv.4 ckey.4
CONFIGURE_ARGS+= --with-libcwnn=-lcwnn --with-cwnn-libraries="${PREFIX}/lib"
.endif
.elif (${WNN} == kWnn)
CONFIGURE_ARGS+=	--enable-Wnn=no --enable-cWnn=no
.if (${PKGNAMESUFFIX} == -server)
#BUILD_DEPENDS=	${LOCALBASE}/lib/libkwnn.a:${PORTSDIR}/korean/FreeWnn-lib
#RUN_DEPENDS=	${LOCALBASE}/lib/wnn/ko_KR/kserverrc:${PORTSDIR}/korean/FreeWnn-lib
LIB_DEPENDS=	kwnn.0:${PORTSDIR}/korean/FreeWnn-lib
CONFIGURE_ARGS+= --with-libkwnn=-lkwnn --with-kwnn-libraries="${PREFIX}/lib"
.endif
.endif

.if (${PKGNAMESUFFIX} == -server)
pre-install:
	${SETENV} BATCH=${BATCH} \
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} \
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
