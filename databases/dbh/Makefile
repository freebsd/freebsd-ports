# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dbh
PORTVERSION=	4.6.2
CATEGORIES=	databases
MASTER_SITES=	http://svn.foo-projects.org/svn/xffm/RELEASES/tarballs/ \
		SF

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Disk Based Hashtables

CONFLICTS=	dbh-[0-3]*

USES=	pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=		dbh.1 dbh.h.1
MAN3=		dbh_close.3 dbh_create.3 dbh_destroy.3 dbh_erase.3 \
		dbh_exit_fanout.3 dbh_exit_sweep.3 dbh_fanout.3 dbh_find.3 \
		dbh_foreach_fanout.3 dbh_foreach_sweep.3 dbh_genkey.3 \
		dbh_genkey2.3 dbh_load.3 dbh_load_address.3 \
		dbh_load_child.3 dbh_load_parent.3 dbh_macros.3 \
		dbh_open.3 dbh_open_ro.3 dbh_orderkey.3 dbh_prune.3 \
		dbh_regen_fanout.3 dbh_regen_sweep.3 dbh_set_data.3 \
		dbh_set_key.3 dbh_set_recordsize.3 dbh_set_size.3 \
		dbh_settempdir.3 dbh_sweep.3 dbh_unerase.3 \
		dbh_unprune.3 dbh_update.3 dbh_writeheader.3

OPTIONS_DEFINE=	GTKDOC EXAMPLES
GTKDOC_DESC=	Enable GTK html documentation

NO_STAGE=	yes

.for a in ia64 powerpc sparc64
BROKEN_${a}=	Does not compile on ia64, powerpc, or sparc64
.endfor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTKDOC}
CONFIGURE_ARGS+=	--enable-gtk-doc-html
PLIST_SUB=	GTKDOC=""
.else
CONFIGURE_ARGS+=	--disable-gtk-doc-html
PLIST_SUB=	GTKDOC="@comment "
.endif

post-patch:
# Needed to remove gtk-doc installation.
.if empty(PORT_OPTIONS:MGTKDOC)
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS = src man\).*|\1|' ${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} '*.c' ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
