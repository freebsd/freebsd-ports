# New ports collection makefile for:	epkg
# Date created:				12 May 2006
# Whom:						Jim Pirzyk <pirzyk@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	epkg
PORTVERSION=	2.3.9
PORTREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.feep.net/pub/encap/epkg/

MAINTAINER=	pirzyk@freebsd.org
COMMENT=	Encap Package Manager

BUILD_DEPENDS=	${LOCALBASE}/lib/libfget.a:${PORTSDIR}/ftp/fget
LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl \
		expat.6:${PORTSDIR}/textproc/expat2

HAS_CONFIGURE=	YES
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${PREFIX}/lib
CONFIGURE_ARGS=	--disable-encap --disable-epkg-install --without-libtar \
		--with-libfget \
		--prefix=${PREFIX}

MAN1=		epkg.1 \
			mkencap.1
MAN3=		encap20_platform_name.3 \
			encap_check.3 \
			encap_check_prereqs.3 \
			encap_check_source.3 \
			encap_check_target.3 \
			encap_close.3 \
			encap_find_versions.3 \
			encap_hash_add.3 \
			encap_hash_del.3 \
			encap_hash_free.3 \
			encap_hash_getkey.3 \
			encap_hash_new.3 \
			encap_hash_next.3 \
			encap_hash_prev.3 \
			encap_hash_search.3 \
			encap_install.3 \
			encap_list_add.3 \
			encap_list_add_str.3 \
			encap_list_del.3 \
			encap_list_dup.3 \
			encap_list_free.3 \
			encap_list_merge.3 \
			encap_list_new.3 \
			encap_list_next.3 \
			encap_list_prev.3 \
			encap_list_search.3 \
			encap_open.3 \
			encap_pkgspec_join.3 \
			encap_pkgspec_parse.3 \
			encap_platform_compat.3 \
			encap_platform_name.3 \
			encap_platform_split.3 \
			encap_remove.3 \
			encap_vercmp.3 \
			encapinfo_free.3 \
			encapinfo_init.3 \
			encapinfo_parse_directive.3 \
			encapinfo_write.3
MAN5=		encap_profile.5

.include <bsd.port.pre.mk>

do-install:
	@(cd ${BUILD_WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install-recurse)

	-@${MKDIR} ${PREFIX}/etc
	@${CP} ${WRKSRC}/mkencap/mkencap_environment ${PREFIX}/etc/mkencap_environment.sample
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
