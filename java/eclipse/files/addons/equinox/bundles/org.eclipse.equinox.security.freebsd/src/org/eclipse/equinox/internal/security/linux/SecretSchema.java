/*******************************************************************************
 * Copyright (c) 2020, 2021 Red Hat Inc.
 *
 * This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License 2.0
 * which accompanies this distribution, and is available at
 * https://www.eclipse.org/legal/epl-2.0/
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *     Red Hat Inc. - initial version
 *******************************************************************************/
package org.eclipse.equinox.internal.security.linux;

import java.util.List;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

public class SecretSchema extends Structure {
	public String name;
	public int flags;
	public SecretSchemaAttribute[] attributes = new SecretSchemaAttribute[32];

	/* <private> */
	public int reserved;
	public Pointer reserved1;
	public Pointer reserved2;
	public Pointer reserved3;
	public Pointer reserved4;
	public Pointer reserved5;
	public Pointer reserved6;
	public Pointer reserved7;

	public SecretSchema(String name, int flags, SecretSchemaAttribute... attributes) {
		this.name = name;
		this.flags = flags;
		for (int i = 0; i < attributes.length; ++i) {
			this.attributes[i] = attributes[i];
		}
		write();
	}

	@Override
	protected List<String> getFieldOrder() {
		return List.of("name", "flags", "attributes", "reserved", "reserved1", "reserved2", "reserved3", "reserved4", //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$ //$NON-NLS-4$ //$NON-NLS-5$ //$NON-NLS-6$ //$NON-NLS-7$ //$NON-NLS-8$
				"reserved5", "reserved6", "reserved7"); //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
	}
}
