# ex:ts=8
# Ports collection makefile for:	dbh
# Date created:			Aug 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dbh
PORTVERSION=	4.6.1
CATEGORIES=	databases
MASTER_SITES=	http://svn.foo-projects.org/svn/xffm/RELEASES/tarballs/ \
		SF

MAINTAINER=	frederic@culot.org
COMMENT=	Disk Based Hashtables

CONFLICTS=	dbh-[0-3]*

USE_GNOME=	gnomehack gnometarget pkgconfig
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

OPTIONS=	GTKDOC "Enable GTK html documentation" off

.include <bsd.port.options.mk>

.if defined(WITH_GTKDOC)
CONFIGURE_ARGS+=	--enable-gtk-doc-html
PLIST_SUB=	GTKDOC=""
.else
CONFIGURE_ARGS+=	--disable-gtk-doc-html
PLIST_SUB=	GTKDOC="@comment "
.endif

post-patch:
# Needed to remove gtk-doc installation.
.if !defined(WITH_GTKDOC)
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS = src man\).*|\1|' ${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} '*.c' ${EXAMPLESDIR})
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
