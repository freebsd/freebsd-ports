# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	2

BOOKS=		glib gobject gio

glib_MAN=	glib-gettextize.1
gobject_MAN=	glib-genmarshal.1 glib-mkenums.1 gobject-query.1

MAN1=		${glib_MAN} ${gobject_MAN}

PLIST=		${.CURDIR}/pkg-plist

do-install:
.for d in ${BOOKS}
	if [ -d ${REFERENCE_SRC}/${d}/html ]; then \
        	${MKDIR} ${PREFIX}/share/doc/${d}; \
		cd ${REFERENCE_SRC}/${d}/html && \
		${FIND} * -type d ! -empty -exec ${MKDIR} "${PREFIX}/share/doc/${d}/{}" \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/share/doc/${d}/{}" \; ; \
	fi
.endfor

post-install:
.for m in glib gobject
	${INSTALL_MAN} ${${m}_MAN:S|^|${REFERENCE_SRC}/${m}/|} \
		${PREFIX}/man/man1
.endfor

# overwrite this from bsd.port.mk, because we not don't honow DOCSDIR
add-plist-docs:
	@${DO_NADA}

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
