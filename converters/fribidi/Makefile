# ex:ts=8
# Ports collection makefile for:	fribidi
# Date created:			Apr 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fribidi
PORTVERSION=	0.19.2
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://fribidi.org/download/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Free Implementation of the Unicode Bidirectional Algorithm

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

MAN3=		fribidi_charset_to_unicode.3 fribidi_debug_status.3 \
		fribidi_get_bidi_type.3 fribidi_get_bidi_type_name.3 \
		fribidi_get_bidi_types.3 fribidi_get_joining_type.3 \
		fribidi_get_joining_type_name.3 fribidi_get_joining_types.3 \
		fribidi_get_mirror_char.3 fribidi_get_par_direction.3 \
		fribidi_get_par_embedding_levels.3 fribidi_get_type.3 \
		fribidi_get_type_internal.3 fribidi_join_arabic.3 \
		fribidi_log2vis.3 fribidi_log2vis_get_embedding_levels.3 \
		fribidi_mirroring_status.3 fribidi_parse_charset.3 \
		fribidi_remove_bidi_marks.3 fribidi_reorder_line.3 \
		fribidi_reorder_nsm_status.3 fribidi_set_debug.3 \
		fribidi_set_mirroring.3 fribidi_set_reorder_nsm.3 \
		fribidi_shape.3 fribidi_shape_mirroring.3 \
		fribidi_unicode_to_charset.3 fribidi_unicode_version.3 \
		fribidi_version_info.3

.include <bsd.port.pre.mk>

.if !defined(WITH_DEBUG)
CONFIGURE_ARGS=	--disable-debug
.endif

post-patch:
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' < \
	    	${FILESDIR}/fribidi-config > ${WRKDIR}/fribidi-config

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/fribidi-config ${PREFIX}/bin

.include <bsd.port.post.mk>
