#ifndef _OPENBSD_COMPAT_SYS_QUEUE_H_
#define _OPENBSD_COMPAT_SYS_QUEUE_H_

#include_next <sys/queue.h>

#define SIMPLEQ_HEAD(name, type) \
	STAILQ_HEAD(name, type)
#define SIMPLEQ_HEAD_INITIALIZER(head) \
	STAILQ_HEAD_INITIALIZER(head)
#define SIMPLEQ_ENTRY(type) \
	STAILQ_ENTRY(type)
#define SIMPLEQ_FIRST(head) \
	STAILQ_FIRST(head)
#define SIMPLEQ_END(head) \
	NULL
#define SIMPLEQ_EMPTY(head) \
	STAILQ_EMPTY(head)
#define SIMPLEQ_NEXT(elm, field) \
	STAILQ_NEXT(elm, field)
#define SIMPLEQ_FOREACH(var, head, field) \
	STAILQ_FOREACH(var, head, field)
#define SIMPLEQ_FOREACH_SAFE(var, head, field, tvar) \
	STAILQ_FOREACH_SAFE(var, head, field, tvar)
#define SIMPLEQ_INIT(head) \
	STAILQ_INIT(head)
#define SIMPLEQ_INSERT_HEAD(head, elm, field) \
	STAILQ_INSERT_HEAD(head, elm, field)
#define SIMPLEQ_INSERT_TAIL(head, elm, field) \
	STAILQ_INSERT_TAIL(head, elm, field)
#define SIMPLEQ_INSERT_AFTER(head, listelm, elm, field) \
	STAILQ_INSERT_AFTER(head, listelm, elm, field)
#define SIMPLEQ_REMOVE_HEAD(head, field) \
	STAILQ_REMOVE_HEAD(head, field)
#define SIMPLEQ_REMOVE_AFTER(head, elm, field) \
	STAILQ_REMOVE_AFTER(head, elm, field)
#define SIMPLEQ_CONCAT(head1, head2) \
	STAILQ_CONCAT(head1, head2)

#endif
