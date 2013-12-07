# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	3

BOOKS=		glib gobject gio

glib_MAN=	glib-gettextize.1
gobject_MAN=	glib-genmarshal.1 glib-mkenums.1 gobject-query.1

do-install:
.for d in ${BOOKS}
	if [ -d ${REFERENCE_SRC}/${d}/html ]; then \
        	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/${d}; \
		cd ${REFERENCE_SRC}/${d}/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/doc/${d}; \
	fi
.endfor

post-install:
.for m in glib gobject
	${INSTALL_MAN} ${${m}_MAN:S|^|${REFERENCE_SRC}/${m}/|} \
		${STAGEDIR}${PREFIX}/man/man1
.endfor

# overwrite this from bsd.port.mk, because we not don't honow DOCSDIR
add-plist-docs:
	@${DO_NADA}

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
